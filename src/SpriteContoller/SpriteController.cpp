#include "SpriteController.hpp"

SpriteController::SpriteController(SettingsManager &settingsManager) {
  toml::table p = toml::get<toml::table>(settingsManager.SpriteSettings);
  for (auto it = p.begin(); it != p.end(); it++) {
    using uint = unsigned int;
    toml::table current = toml::get<toml::table>(it->second);
    std::string path = toml::get<std::string>(current["path"]);
    std::pair<uint, uint> size = toml::get<decltype(size)>(current["size"]);
    load_sprites(it->first, toml::get<std::string>(current["path"]),
                 {size.first, size.second});
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
  sprites[name] = make_sprite(textures[name], tilesize);
}

std::vector<sf::Sprite> SpriteController::make_sprite(sf::Texture &texture,
                                                      sf::Vector2u tilesize) {
  TileMap tilemap(texture, tilesize);
  auto sprites = tilemap.get_sprites();
  return sprites;
}