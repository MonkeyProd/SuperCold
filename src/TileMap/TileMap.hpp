#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap {
	sf::Texture &m_tileset;
	sf::Vector2u m_tile_size;
	std::vector<sf::Sprite> m_sprites;

  public:
	/**
	 * @brief Класс, создающий вектор спрайтов из текстуры
	 * @param tileset ссылка на текстуру
	 * @param tile_size размер тайлов в текстуре
	 */
	TileMap(sf::Texture &tileset, const sf::Vector2u &tile_size);

	/**
	 * @brief Метод, возращающий созданный вектор спрайтов
	 */
	std::vector<sf::Sprite> get_sprites();
};
