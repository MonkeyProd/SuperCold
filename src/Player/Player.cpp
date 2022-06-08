#include "Player.hpp"

Player::Player()
    : m_position{0, 0}, m_velocity{0, 0}, m_playerObject{}, m_speed(5){};

Player::Player(sf::Vector2f startPosition, sf::Vector2f velocity,
               AnimatedGameObject &playerObject, float speed)
    : m_position(startPosition),
      m_velocity(velocity),
      m_playerObject(playerObject),
      m_speed(speed),
      isLookRight(true) {}

AnimatedGameObject &Player::get_playerObject() { return m_playerObject; }

void Player::moveLeft() { m_velocity.x = -m_speed; }
void Player::moveRight() { m_velocity.x = m_speed; }
void Player::moveTop() { m_velocity.y = -m_speed; }
void Player::moveDown() { m_velocity.y = m_speed; }
void Player::resetHorizontalVelocity() { m_velocity.x = 0; }
void Player::resetVerticalVelocity() { m_velocity.y = 0; }
void Player::setSpeed(float speed) { m_speed = speed; }
void Player::movePlayer(sf::Time deltaTime) {
  move(m_velocity * deltaTime.asSeconds());
  m_position = getPosition();
  m_playerObject.move(
      m_velocity *
      deltaTime.asSeconds());  //Здесь надо подумать  как одним мувом обойтись
}
void Player::movePlayer(sf::Time deltaTime, sf::Vector2f velocity) {
  move(velocity * deltaTime.asSeconds());
  m_position = getPosition();
  m_playerObject.move(
      velocity *
      deltaTime.asSeconds());  //Здесь надо подумать  как одним мувом обойтись
}

void Player::mirrorSprite(bool isRight) {
  if (isLookRight != isRight) {
    m_playerObject.flip();
    isLookRight = isRight;
  }
}
sf::Vector2f Player::getPlayerPosition() const { return m_position; }
sf::Vector2f Player::getPlayerVelocity() const { return m_velocity; }
sf::FloatRect Player::getNextPosition(sf::Time deltaTime) const {
  sf::FloatRect nextPosition(m_playerObject.getPosition(),
                             {m_playerObject.m_sprite.getGlobalBounds().height *
                                  m_playerObject.m_scale,
                              m_playerObject.m_sprite.getGlobalBounds().width *
                                  m_playerObject.m_scale});
  nextPosition.top += m_velocity.y * deltaTime.asSeconds();
  nextPosition.left += m_velocity.x * deltaTime.asSeconds();
  return nextPosition;
}
void Player::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
  surface.draw(m_playerObject);
}