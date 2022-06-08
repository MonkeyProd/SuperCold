#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f startPosition, sf::Vector2f velocity,
               std::vector<sf::Sprite> bulletSprite, BulletSide bulletSide)
    : m_bulletObject(startPosition, bulletSprite, false, 3),
      m_velocity(velocity) {
  switch (bulletSide) {
    case BulletSide::Left:
      m_bulletObject.setRotation(180);
      break;
    case BulletSide::Up:
      m_bulletObject.setRotation(-90);
      break;
    case BulletSide::Down:
      m_bulletObject.setRotation(90);
      break;

    default:
      break;
  }
}

void Bullet::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
  surface.draw(m_bulletObject);
}

AnimatedGameObject &Bullet::getBulletObject() { return m_bulletObject; }

void Bullet::moveBullet(sf::Time deltaTime) {
  move(m_velocity * deltaTime.asSeconds());
  m_bulletObject.move(m_velocity * deltaTime.asSeconds());
}