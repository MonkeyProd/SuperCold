#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "../SettingsManager/SettingsManager.hpp"
#include "../TileMap/TileMap.hpp"
/**
 * SpriteController is the struct that contains all textures and sprites you
 * have in the game
 */

struct SpriteController {
  std::map<std::string, sf::Texture> textures;
  std::map<std::string, std::vector<sf::Sprite>> spriteArrays;
  std::map<std::string, sf::Sprite> spriteObjects;

  std::pair<int, int> tilemap_size;

  SpriteController() = default;
  SpriteController(SettingsManager &settingsManager);

  /**
   * load_texture(name, path) load texture from path and load it to textures map
   */
  void load_textures(std::string name, std::string path);
  /**
   * load_sprites(name, path) load texture from path and load it to textures map
   * make sprite array from it and load it to sprites map
   */
  void load_sprites(std::string name, std::string path, sf::Vector2u tilesize);
  /**
   * make_sprite(texture, tilesize) creates sprite from texture
   *
   */
  std::vector<sf::Sprite> make_sprite(sf::Texture &texture,
                                      sf::Vector2u tilesize);

  void configureSprites(toml::value TileIndexSettings);

  int indexesToindex(int i, int j);
};
