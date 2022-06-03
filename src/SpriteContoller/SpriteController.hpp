#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "../TileMap/TileMap.hpp"

/**
 * SpriteController is the struct that contains all textures and sprites you
 * have in the game
 *
 * Also it have  map <textures_path> which contains paths and sizes for
 * everthing you gonna load in the start of the game
 */

struct SpriteController {
  std::map<std::string, std::pair<std::string, sf::Vector2u>> texture_paths = {
      {"world", {"../src/Assets/my_tileset.jpg", {8, 8}}},
      {"player", {"../src/Assets/player2.png", {16, 16}}}};

  std::map<std::string, sf::Texture> textures;
  std::map<std::string, std::vector<sf::Sprite>> sprites;

  SpriteController();

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
};