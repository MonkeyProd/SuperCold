#include "TileMap.hpp"

TileMap::TileMap(sf::Texture &tileset, const sf::Vector2u &tile_size)
    : m_tileset(tileset), m_tile_size(tile_size) {
  sf::Vector2u tileset_size = m_tileset.getSize();
  int rows = tileset_size.y / tile_size.y;
  int cols = tileset_size.x / tile_size.x;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sf::IntRect rect;
      rect.left = j * tile_size.x;
      rect.top = i * tile_size.y;
      rect.width = tile_size.x;
      rect.height = tile_size.y;
      m_sprites.push_back(sf::Sprite(m_tileset, rect));
    }
  }
};

std::vector<sf::Sprite> TileMap::get_sprites() { return m_sprites; }