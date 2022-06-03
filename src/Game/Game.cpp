#include "Game.hpp"
Game::Game(unsigned int h, unsigned int w)
    : WINDOW_SIZE_H(h),
      WINDOW_SIZE_W(w),
      window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
                              "Smart Slimes",
                              sf::Style::Titlebar | sf::Style::Close)),
      FPS{10},
      paused{false} {}

void Game::ProcessEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed: {
        window.close();
        break;
      }
      case sf::Event::KeyPressed: {
        // printf("pizda\n");
        switch (event.key.code) {
          case sf::Keyboard::Q: {
            window.close();
            break;
          }
          case sf::Keyboard::Space: {
            paused = !paused;
            break;
          }

          default:
            break;
        }
      }
      default:
        break;
    }
  }
}

/**
 * There animation state of each object in animatedLayer is changing
 */
void Game::update(sf::Time deltatime) {
  for (auto &object : animatedLayer) {
    object.nextState();
  }
}

/**
 * Drawing all layers
 */
void Game::draw() {
  window.clear(sf::Color(16, 0, 41));
  for (auto &object : drawLayer) {
    window.draw(object);
  }
  for (auto &object : animatedLayer) {
    window.draw(object);
  }
  window.display();
}

void Game::run() {
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / FPS);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  auto sprites = spriteController.sprites["world"];
  auto player_sprites = spriteController.sprites["player"];

  draw_test_room(sprites);
  draw_animated_player(player_sprites, 300, 300);
  draw_animated_player(player_sprites, 400, 500);

  while (window.isOpen()) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      ProcessEvents();
      if (not paused) {
        update(timePerFrame);
      }
    }
    draw();
  }
}

void Game::draw_test_room(std::vector<sf::Sprite> sprites) {
  int scale = 8;
  int size_x = 10;
  int size_y = 10;
  int x_offset = 100;
  int y_offset = 100;
  for (int i = 0; i <= size_y * 8 * scale; i += 8 * scale) {
    for (int j = 0; j <= size_x * 8 * scale; j += 8 * scale) {
      GameObject floor;
      if (i == size_y * 8 * scale || i == 0 || j == 0 ||
          j == size_x * 8 * scale)
        floor = {sf::Vector2f(x_offset + i, y_offset + j), sprites[3]};
      else {
        int sprite_id = rand() % 3;
        floor = {sf::Vector2f(x_offset + i, y_offset + j), sprites[sprite_id]};
      }
      floor.setScale(scale, scale);
      drawLayer.push_back(floor);
    }
  }
}

void Game::draw_animated_player(std::vector<sf::Sprite> sprites, float x,
                                float y) {
  AnimatedGameObject player({x, y}, sprites);
  player.setScale(5, 5);
  animatedLayer.push_back(player);
}