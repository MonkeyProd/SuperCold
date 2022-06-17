#include "SpriteController.hpp"

SpriteController::SpriteController(SettingsManager &settingsManager) {
  tilemap_size = toml::find<decltype(tilemap_size)>(
      settingsManager.TileMapSettings, "size");
  toml::table generalSpritesTable =
      toml::get<toml::table>(settingsManager.SpriteSettings);
  processSettings(generalSpritesTable);

  toml::table playerSpritesTable =
      toml::get<toml::table>(settingsManager.PlayerSpritesSettings);
  processSettings(playerSpritesTable, true);

  configureSprites(settingsManager.TileIndexes);
}

void SpriteController::processSettings(toml::table &table,
                                       bool isPlayerSettings) {
  for (auto it = table.begin(); it != table.end(); it++) {
    using uint = unsigned int;
    toml::table current = toml::get<toml::table>(it->second);
    std::string path = toml::get<std::string>(current["path"]);
    std::pair<uint, uint> size = toml::get<decltype(size)>(current["size"]);
    if (isPlayerSettings)
      load_player_sprites(it->first, toml::get<std::string>(current["path"]),
                          {size.first, size.second});
    else
      load_sprites(it->first, toml::get<std::string>(current["path"]),
                   {size.first, size.second});
    printf("%s loaded.\n", it->first.c_str());
  }
}

void SpriteController::load_textures(std::string name, std::string path) {
  sf::Texture tileset;
  if (!tileset.loadFromFile(path)) {
    printf("Textures for %s not found!\n", name.c_str());
  }
  textures[name] = tileset;
}

void SpriteController::load_sprites(std::string name, std::string path,
                                    sf::Vector2u tilesize) {
  load_textures(name, path);
  spriteArrays[name] = make_sprite(textures[name], tilesize);
}

void SpriteController::load_player_sprites(std::string name, std::string path,
                                           sf::Vector2u tilesize) {
  load_textures(name, path);
  playerSprites[name] = make_sprite(textures[name], tilesize);
}

std::vector<sf::Sprite> SpriteController::make_sprite(sf::Texture &texture,
                                                      sf::Vector2u tilesize) {
  TileMap tilemap(texture, tilesize);
  auto sprites = tilemap.get_sprites();
  return sprites;
}

void SpriteController::configureSprites(toml::value TileIndexSettings) {
  toml::table tileIndexes = toml::get<toml::table>(TileIndexSettings);
  for (auto it = tileIndexes.begin(); it != tileIndexes.end(); it++) {
    auto indexes = toml::get<std::pair<int, int>>(it->second);
    int index = indexesToindex(indexes.first, indexes.second);
    spriteObjects[it->first] = spriteArrays["world"][index];
  }
}

int SpriteController::indexesToindex(int i, int j) {
  return i * tilemap_size.second + j;
}