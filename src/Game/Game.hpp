#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../GameObject/AnimatedGameObject.hpp"
#include "../GameObject/GameObject.hpp"
#include "../SpriteContoller/SpriteController.hpp"
#include "../TileMap/TileMap.hpp"

class Game {
 private:
  unsigned int WINDOW_SIZE_H;
  unsigned int WINDOW_SIZE_W;
  sf::RenderWindow window;
  void ProcessEvents();
  void update(sf::Time deltatime);
  void draw();
  uint8_t FPS;
  bool paused;
  SpriteController spriteController;

  std::vector<GameObject> drawLayer;
  std::vector<AnimatedGameObject> animatedLayer;

  void draw_test_room(std::vector<sf::Sprite> sprites);
  void draw_animated_player(std::vector<sf::Sprite> sprites, float x, float y);

 public:
  Game(unsigned int h = 600U, unsigned int w = 800U);
  void run();
};
