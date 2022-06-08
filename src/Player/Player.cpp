#include "Player.hpp"

Player::Player(sf::Vector2f startPosition, sf::Vector2f velocity,
               std::vector<sf::Sprite> playerRunForward,
               std::vector<sf::Sprite> playerRunBack,
               std::vector<sf::Sprite> playerRunLeft,
               std::vector<sf::Sprite> playerRunRight,
               std::vector<sf::Sprite> playerForward,
               std::vector<sf::Sprite> playerBack,
               std::vector<sf::Sprite> playerLeft,
               std::vector<sf::Sprite> playerRight, std::string footsteps_path,
               float speed)
    : m_position(startPosition),
      m_velocity(velocity),
      m_playerRunForward(playerRunForward),
      m_playerRunBack(playerRunBack),
      m_playerRunLeft(playerRunLeft),
      m_playerRunRight(playerRunRight),
      m_playerForward(playerForward),
      m_playerBack(playerBack),
      m_playerLeft(playerLeft),
      m_playerRight(playerRight),
      m_speed(speed),
      isLookRight(true) {
  AnimatedGameObject playerObject({startPosition.x - 8, startPosition.y - 8},
                                  m_playerForward, false, 4);
  m_playerObject = playerObject;
  m_current_state = m_playerForward;
  m_sbuffer.loadFromFile(footsteps_path);
  m_footstepsSound.setBuffer(m_sbuffer);
  m_footstepsSound.setVolume(80);
  m_footstepsSound.setPitch(1);
  m_footstepsSound.setLoop(true);
}

AnimatedGameObject &Player::get_playerObject() { return m_playerObject; }

void Player::moveLeft() {
  m_velocity.x = -m_speed;
  isMoveHorizontal = true;
}
void Player::moveRight() {
  m_velocity.x = m_speed;
  isMoveHorizontal = true;
}
void Player::moveTop() {
  m_velocity.y = -m_speed;
  isMoveVertical = true;
}
void Player::moveDown() {
  m_velocity.y = m_speed;
  isMoveVertical = true;
}
void Player::resetHorizontalVelocity() {
  m_velocity.x = 0;
  isMoveHorizontal = false;
}
void Player::resetVerticalVelocity() {
  m_velocity.y = 0;
  isMoveVertical = false;
}
void Player::setSpeed(float speed) { m_speed = speed; }
void Player::movePlayer(sf::Time deltaTime) {
  if ((isMoveHorizontal || isMoveVertical) && !isStepping) {
    printf("HERE\n");
    m_footstepsSound.setBuffer(m_sbuffer);
    m_footstepsSound.play();
    isStepping = true;
  } else {
    if (isStepping && !(isMoveHorizontal || isMoveVertical)) {
      m_footstepsSound.pause();
      isStepping = false;
    }
  }
  if (m_velocity.y > 0) {
    m_playerObject.m_sprites_array = m_playerRunForward;
    m_current_state = m_playerForward;
  } else if (m_velocity.y < 0) {
    m_playerObject.m_sprites_array = m_playerRunBack;
    m_current_state = m_playerBack;
  } else if (m_velocity.x < 0) {
    m_playerObject.m_sprites_array = m_playerRunLeft;
    m_current_state = m_playerLeft;
  } else if (m_velocity.x > 0) {
    m_playerObject.m_sprites_array = m_playerRunRight;
    m_current_state = m_playerRight;
  }
  if (m_velocity.x == 0 && m_velocity.y == 0) {
    m_playerObject.m_sprites_array = m_current_state;
  }
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
  sf::CircleShape shadow(20);
  shadow.setPosition({m_playerObject.getPosition().x + 10,
                      m_playerObject.getPosition().y + 45});
  shadow.setScale(1.3, 1);
  shadow.setFillColor(sf::Color(50, 50, 50, 100));
  surface.draw(shadow);
  surface.draw(m_playerObject);
}