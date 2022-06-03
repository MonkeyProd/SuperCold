#include "Game.hpp"

Game::Game(unsigned int h, unsigned int w)
    : WINDOW_SIZE_H(h),
      WINDOW_SIZE_W(w),
      window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
                              "Smart Slimes",
                              sf::Style::Titlebar | sf::Style::Close)),
      FPS{70},
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

void Game::update(sf::Time deltatime) {
  // call update method for all game objects
}

void Game::draw() {
  // clear and fill the window with color
  window.clear(sf::Color(16, 0, 41));
  // call display method for all game objects

  sf::Texture tl_t;
  if (!tl_t.loadFromFile("../src/Assets/my_tileset.jpg")) {
    printf("not loaded\n");
  }
  sf::Texture pl_t;
  if (!pl_t.loadFromFile("../src/Assets/player.png")) {
    printf("not loaded\n");
  }
  TileMap tl(tl_t, sf::Vector2u(8, 8));
  auto sprites = tl.get_spites();
  TileMap pl(pl_t, sf::Vector2u(20, 22));
  auto pl_sprites = pl.get_spites();
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
      window.draw(floor);
    }
  }
  GameObject player(sf::Vector2f(200, 200), pl_sprites[0]);
  player.setScale(scale / 2, scale / 2);
  window.draw(player);
  window.display();
}

void Game::run() {
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / FPS);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  bool isDrawed = false;
  while (window.isOpen()) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      ProcessEvents();
      if (not paused) {
        update(timePerFrame);
      }
    }
    if (!isDrawed) draw();  // FIXME: Временная залупа
    isDrawed = true;
  }
}
