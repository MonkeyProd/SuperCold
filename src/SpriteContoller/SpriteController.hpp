#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "../SettingsManager/SettingsManager.hpp"
#include "../TileMap/TileMap.hpp"

struct SpriteController {
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, std::vector<sf::Sprite>> spriteArrays;
	std::map<std::string, sf::Sprite> spriteObjects;
	std::map<std::string, std::vector<sf::Sprite>> playerSprites;

	std::pair<int, int> tilemap_size;

	SpriteController() = default;

	/**
	 * @brief Структура, содержащая все спрайты и текстуры
	 * @param settingsManager ссылка на структуру с настройками
	 */
	SpriteController(SettingsManager &settingsManager);

	/**
	 * @brief Метод, обрабатывающий определенную таблицу из настроек с спрайтами
	 * @param table ссылка на таблицу
	 * @param isPlayerSettings является ли настройками игрока
	 */
	void processSettings(toml::table &table, bool isPlayerSettings = false);

	/**
	 * @brief Метод, обрабатывающий текстуры
	 * @param name название текстуры
	 * @param path путь до текстуры
	 */
	void load_textures(std::string name, std::string path);

	/**
	 * @brief Метод, создающий спрайты игрока
	 * @param name название спрайта
	 * @param path путь до текстуры
	 * @param tilesize размер тайлов в текстуре
	 */
	void load_player_sprites(std::string name, std::string path,
	                         sf::Vector2u tilesize);
	/**
	 * @brief Метод, создающий спрайты
	 * @param name название спрайта
	 * @param path путь до текстуры
	 * @param tilesize размер тайлов в текстуре
	 */
	void load_sprites(std::string name, std::string path,
	                  sf::Vector2u tilesize);
	/**
	 * @brief Метод, создающий спрайты из текстуры
	 * @param texture ссылка на текстуру
	 * @param tilesize размер тайлов в текстуре
	 */
	std::vector<sf::Sprite> make_sprite(sf::Texture &texture,
	                                    sf::Vector2u tilesize);

	/**
	 * @brief Метод, организующий из спрайтов и индексов тайлов заданных в
	 * настройках словарь
	 * @param TileIndexSettings настройки, задающие для каждого тайла его
	 * название и его индексы
	 */
	void configureSprites(toml::value TileIndexSettings);

	/**
	 * @brief Метод, преобразующий индексы двумерного массива в индексы одномерного
	 */
	int indexesToindex(int i, int j);
};
