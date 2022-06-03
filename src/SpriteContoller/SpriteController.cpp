#include "SpriteController.hpp"

SpriteController::SpriteController() {
  for (auto it = texture_paths.begin(); it != texture_paths.end(); it++) {
    load_sprites(it->first, it->second.first, it->second.second);
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