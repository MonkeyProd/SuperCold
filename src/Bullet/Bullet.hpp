#pragma once
#include <../GameObject/GameObject.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable {
  GameObject m_bulletObject;
  sf::Vector2f m_velocity;

 public:
  bool isExist = true;
  Bullet(sf::Vector2f startPosition, sf::Vector2f velocity,
         std::vector<sf::Sprite> bulletSprite);

  GameObject &getBulletObject();
  void moveBullet(sf::Time deltaTime);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

  sf::FloatRect getBulletRect();
};