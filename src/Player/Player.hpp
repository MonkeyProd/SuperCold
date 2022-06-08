#pragma once
#include <SFML/Graphics.hpp>

#include "../GameObject/AnimatedGameObject.hpp"
#include "../SpriteContoller/SpriteController.hpp"

class Player : public sf::Drawable, public sf::Transformable {
  sf::Vector2f m_velocity;
  sf::Vector2f m_position;

  std::vector<sf::Sprite> m_playerRunForward;
  std::vector<sf::Sprite> m_playerRunBack;
  std::vector<sf::Sprite> m_playerRunLeft;
  std::vector<sf::Sprite> m_playerRunRight;
  std::vector<sf::Sprite> m_playerForward;
  std::vector<sf::Sprite> m_playerBack;
  std::vector<sf::Sprite> m_playerLeft;
  std::vector<sf::Sprite> m_playerRight;

  std::vector<sf::Sprite> m_current_state;

  AnimatedGameObject m_playerObject;
  float m_speed;
  bool isLookRight;

 public:
  Player() = default;
  Player(sf::Vector2f startPosition, sf::Vector2f velocity,
         std::vector<sf::Sprite> playerRunForward,
         std::vector<sf::Sprite> playerRunBack,
         std::vector<sf::Sprite> playerRunLeft,
         std::vector<sf::Sprite> playerRunRight,
         std::vector<sf::Sprite> playerForward,
         std::vector<sf::Sprite> playerBack, std::vector<sf::Sprite> playerLeft,
         std::vector<sf::Sprite> playerRight, float speed = 100);

  void moveLeft();
  void moveRight();
  void moveTop();
  void moveDown();
  void resetHorizontalVelocity();
  void resetVerticalVelocity();
  void movePlayer(sf::Time deltaTime);
  void movePlayer(sf::Time deltaTime, sf::Vector2f velocity);
  void mirrorSprite(bool isRight);
  void setSpeed(float speed);
  sf::Vector2f getPlayerPosition() const;
  sf::Vector2f getPlayerVelocity() const;
  sf::FloatRect getNextPosition(sf::Time deltaTime) const;

  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

  AnimatedGameObject &get_playerObject();
};
