#include "SettingsManager.hpp"

SettingsManager::SettingsManager(std::string path) {
  auto table = toml::parse(path);
  PlayerSettings = toml::find(table, "player");
  SpriteSettings = toml::find(table, "sprites");
  TileMapSettings = toml::find(table, "tilemap");
  TileIndexes = toml::find(table, "tileindex");
}
