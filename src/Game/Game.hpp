#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Bullet/Bullet.hpp"
#include "../Enemies/EyeEnemy.hpp"
#include "../GameObject/AnimatedGameObject.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Player/Player.hpp"
#include "../SettingsManager/SettingsManager.hpp"
#include "../SpriteContoller/SpriteController.hpp"
#include "../TileMap/TileMap.hpp"
#include "../external/SimplexNoise/SimplexNoise.hpp"
#include "Utils/debug.hpp"

class Game {
 private:
  unsigned int WINDOW_SIZE_H;
  unsigned int WINDOW_SIZE_W;
  uint8_t FPS;
  bool paused;

  sf::RenderWindow window;

  SpriteController spriteController;
  SettingsManager settingsManager;

  Player player;
  sf::View camera;
  sf::View map;

  std::vector<GameObject> drawLayer;
  std::vector<Bullet> bulletLayer;
  std::vector<AnimatedGameObject> animatedLayer;

  // TEMP
  std::vector<EyeEnemy> enemies;

  void ProcessEvents();
  void update(sf::Time deltatime);
  void updateAnimations(sf::Time deltatime);

  void draw(sf::Time deltaTime);
  void draw_world(std::vector<sf::Sprite> sprites);
  void draw_test_room(std::vector<sf::Sprite> sprites);
  void draw_animated_player(std::vector<sf::Sprite> sprites, float x, float y);

 public:
  Game(unsigned int h = 600U, unsigned int w = 800U);
  void run();
};
