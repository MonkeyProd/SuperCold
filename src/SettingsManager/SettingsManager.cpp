#include "SettingsManager.hpp"

SettingsManager::SettingsManager(std::string path) {
  auto table = toml::parse(path);
  PlayerSettings = toml::find(table, "player");
  PlayerSpritesSettings = toml::find(table, "player_sprites");
  SpriteSettings = toml::find(table, "sprites");
  TileMapSettings = toml::find(table, "tilemap");
  TileIndexes = toml::find(table, "tileindex");
  SoundSettings = toml::find(table, "sounds");
  WorldGenSettings = toml::find(table, "world");
  EnemySettings = toml::find(table, "enemy");
}
