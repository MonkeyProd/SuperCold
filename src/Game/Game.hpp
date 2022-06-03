#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../GameObject/GameObject.hpp"
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

 public:
  Game(unsigned int h = 600U, unsigned int w = 800U);
  void run();
};
