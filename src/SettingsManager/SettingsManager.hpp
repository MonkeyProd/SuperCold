#pragma once
#include <string>

#include "../external/toml.hpp"

struct SettingsManager {
  SettingsManager(std::string settingsPath = "../src/settings.toml");
  toml::value PlayerSettings;
  toml::value SpriteSettings;

  template <typename T>
  T get(toml::value settingsType, std::string key) {
    return toml::find<T>(settingsType, key);
  }
};