#pragma once
#include <string>

#include "../external/toml.hpp"

struct SettingsManager {
  SettingsManager(std::string settingsPath = "../src/settings.toml");
  toml::value PlayerSettings;
  toml::value PlayerSpritesSettings;
  toml::value SpriteSettings;
  toml::value TileIndexes;
  toml::value TileMapSettings;
  toml::value SoundSettings;
  toml::value WorldGenSettings;

  template <typename T>
  T get(toml::value settingsType, std::string key) {
    return toml::find<T>(settingsType, key);
  }
};
