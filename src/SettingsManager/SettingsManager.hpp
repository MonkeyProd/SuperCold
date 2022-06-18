#pragma once
#include <string>

#include "../external/toml.hpp"

struct SettingsManager {

	/**
	 * @brief Структура содержащий все настройки игры
	 * @param settingsPath путь к файлу настроек игры (toml)
	 */
	SettingsManager(std::string settingsPath = "../src/settings.toml");
	toml::value PlayerSettings;
	toml::value PlayerSpritesSettings;
	toml::value SpriteSettings;
	toml::value TileIndexes;
	toml::value TileMapSettings;
	toml::value SoundSettings;
	toml::value WorldGenSettings;
	toml::value EnemySettings;

	/**
	 * @brief Метод, возращающий настройку по ключу
	 * @param settingsType интересующий список настроек
	 * @param key ключ(название) настройки
	 * @param T тип настройки
	 */
	template <typename T> T get(toml::value settingsType, std::string key) {
		return toml::find<T>(settingsType, key);
	}
};
