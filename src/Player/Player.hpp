#pragma once
#include <SFML/Graphics.hpp>

#include "../GameObject/AnimatedGameObject.hpp"

class Player : public sf::Drawable, public sf::Transformable {
  sf::Vector2f m_velocity;
  sf::Vector2f m_position;
  AnimatedGameObject m_playerObject;
  float m_speed;
  bool isLookRight;

 public:
  Player();
  Player(sf::Vector2f startPosition, sf::Vector2f velocity,
         AnimatedGameObject &playerObject, float speed = 5);

  void moveLeft();
  void moveRight();
  void moveTop();
  void moveDown();
  void resetHorizontalVelocity();
  void resetVerticalVelocity();
  void movePlayer(sf::Time deltaTime);
  void mirrorSprite(bool isRight);
  sf::Vector2f getPlayerPosition();

  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

  AnimatedGameObject &get_playerObject();
};