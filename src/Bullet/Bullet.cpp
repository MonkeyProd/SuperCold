#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f startPosition, sf::Vector2f velocity,
               std::vector<sf::Sprite> bulletSprite)
    : m_bulletObject(startPosition, bulletSprite, false, 3),
      m_velocity(velocity) {
	m_lifetime = sf::Time();
	if (m_velocity.x < 0)
		m_bulletObject.setRotation(180);
	else if (m_velocity.y > 0)
		m_bulletObject.setRotation(90);
	else if (m_velocity.y < 0)
		m_bulletObject.setRotation(-90);
}

void Bullet::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
	surface.draw(m_bulletObject);
}

sf::FloatRect Bullet::getBulletRect() {
	sf::FloatRect bulletRect(m_bulletObject.getPosition(),
	                         {m_bulletObject.m_sprite.getGlobalBounds().height *
	                              m_bulletObject.m_scale,
	                          m_bulletObject.m_sprite.getGlobalBounds().width *
	                              m_bulletObject.m_scale});
	return bulletRect;
}

GameObject &Bullet::getBulletObject() { return m_bulletObject; }

void Bullet::moveBullet(sf::Time deltaTime) {
	m_lifetime+=deltaTime;
	if(m_lifetime.asSeconds() > 5)
		isExist = false;
	move(m_velocity * deltaTime.asSeconds());
	m_bulletObject.move(m_velocity * deltaTime.asSeconds());
}
