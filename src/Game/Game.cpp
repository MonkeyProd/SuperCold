#include "Game.hpp"

#include "cmath"
using std::atan2;
Game::Game(unsigned int h, unsigned int w)
    : WINDOW_SIZE_H(h),
      WINDOW_SIZE_W(w),
      window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
                              "Smart Slimes",
                              sf::Style::Titlebar | sf::Style::Close)),
      FPS{60},
      paused{false},
      camera(sf::FloatRect(0, 0, WINDOW_SIZE_W, WINDOW_SIZE_H)) {}

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
          case sf::Keyboard::A: {
            player.moveLeft();

            break;
          }
          case sf::Keyboard::D: {
            player.moveRight();
            break;
          }
          case sf::Keyboard::W: {
            player.moveTop();
            break;
          }
          case sf::Keyboard::S: {
            player.moveDown();
            break;
          }
          case sf::Keyboard::LShift: {
            player.setSpeed(settings.player_settings["run_speed"]);
            break;
          }
          default:
            break;
        }
        break;
      }
      case sf::Event::KeyReleased: {
        switch (event.key.code) {
          case sf::Keyboard::A:
          case sf::Keyboard::D:
            player.resetHorizontalVelocity();
            break;
          case sf::Keyboard::W:
          case sf::Keyboard::S:
            player.resetVerticalVelocity();
            break;
          case sf::Keyboard::LShift: {
            player.setSpeed(settings.player_settings["speed"]);
            break;
          }
          default:
            break;
        }
        break;
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
  camera.setCenter(player.getPlayerPosition());
  player.movePlayer(deltatime);
}

void Game::updateAnimations(sf::Time deltatime) {
  for (auto &object : animatedLayer) {
    object.nextState();
  }
  player.get_playerObject().nextState();
}

/**
 * Drawing all layers
 */
void Game::draw(sf::Time deltaTime) {
  window.setView(camera);
  window.clear(sf::Color(16, 0, 41));
  for (auto &object : drawLayer) {
    window.draw(object);
  }
  for (auto &object : animatedLayer) {
    window.draw(object);
  }

  // TEST
  spriteController.load_sprites("crosshair", "../src/Assets/crosshair.png",
                                {8, 8});
  auto sprite = spriteController.sprites["crosshair"][0];
  auto localMousePos = sf::Mouse::getPosition(window);
  auto worldPos = window.mapPixelToCoords(localMousePos);
  GameObject cursor({(float)worldPos.x - 20, (float)worldPos.y - 20}, sprite);
  cursor.setScale(5, 5);
  if (worldPos.x < player.getPlayerPosition().x) {
    player.mirrorSprite(false);
  } else {
    player.mirrorSprite(true);
  }

  window.draw(cursor);
  window.draw(player);

  window.display();
}

void Game::run() {
  sf::Vector2f startPlayerPosition(0, 0);
  window.setMouseCursorVisible(false);
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / FPS);
  sf::Time timePerAnimation = sf::seconds(1.0f / 10);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time timeSinceLastAnimation = sf::Time::Zero;

  auto sprites = spriteController.sprites["world"];
  auto player_sprites = spriteController.sprites["player"];

  draw_test_room(sprites);

  AnimatedGameObject npcObject({500, 500}, player_sprites);
  npcObject.setScale(5, 5);
  animatedLayer.push_back(npcObject);

  // Creating player
  AnimatedGameObject playerObject(
      {startPlayerPosition.x - 8, startPlayerPosition.y - 8}, player_sprites,
      false, 5);

  Player new_player(startPlayerPosition, {0, 0}, playerObject,
                    settings.player_settings["speed"]);
  player = new_player;

  while (window.isOpen()) {
    auto deltaTime = clock.restart();
    timeSinceLastUpdate += deltaTime;
    timeSinceLastAnimation += deltaTime;
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      ProcessEvents();
      if (not paused) {
        update(timePerFrame);
      }
    }
    while (timeSinceLastAnimation > timePerAnimation) {
      timeSinceLastAnimation -= timePerAnimation;
      if (not paused) {
        updateAnimations(timePerAnimation);
      }
    }
    draw(deltaTime);
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
        floor = {sf::Vector2f(x_offset + i, y_offset + j), sprites[3], true, 8};
      else {
        int sprite_id = rand() % 3;
        floor = {sf::Vector2f(x_offset + i, y_offset + j), sprites[sprite_id],
                 false, 8};
      }
      drawLayer.push_back(floor);
    }
  }
}
