#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap {
  sf::Texture m_tileset;
  sf::Vector2u m_tile_size;
  std::vector<sf::Sprite> m_sprites;

 public:
  TileMap();
  TileMap(const sf::Texture &tileset, const sf::Vector2u &tile_size);

  std::vector<sf::Sprite> get_spites();
};