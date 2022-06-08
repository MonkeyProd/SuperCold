#pragma once
#include <../GameObject/AnimatedGameObject.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable {
  AnimatedGameObject m_bulletObject;
  sf::Vector2f m_velocity;

 public:
  bool isExist = true;
  enum BulletSide { Up, Down, Left, Right };
  Bullet(sf::Vector2f startPosition, sf::Vector2f velocity,
         std::vector<sf::Sprite> bulletSprite, BulletSide bulletSide);

  AnimatedGameObject &getBulletObject();
  void moveBullet(sf::Time deltaTime);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
};