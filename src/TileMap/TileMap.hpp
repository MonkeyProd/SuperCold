#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * TileMap class is the helper class that make sprite array from tileset and
 * contains it in itself
 */
class TileMap {
  sf::Texture &m_tileset;
  sf::Vector2u m_tile_size;
  std::vector<sf::Sprite> m_sprites;

 public:
  /**
   * When initialized sprite array is generated
   */
  TileMap(sf::Texture &tileset, const sf::Vector2u &tile_size);

  std::vector<sf::Sprite> get_sprites();
};
