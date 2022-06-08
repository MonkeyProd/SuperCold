#include "EyeEnemy.hpp"

EyeEnemy::EyeEnemy(sf::Vector2f startPosition,
                   std::vector<sf::Sprite> moveSprites,
                   std::vector<sf::Sprite> attackSprites,
                   std::vector<sf::Sprite> takeDamageSprites,
                   std::vector<sf::Sprite> deathSprites, float speed,
                   float attack_distance, std::string enemyHitSound, int health)
    : m_moveSprites(moveSprites),
      m_attackSprites(attackSprites),
      m_takeDamageSprites(takeDamageSprites),
      m_deathSprites(deathSprites),
      m_speed(speed),
      m_EyeEnemyObject(startPosition, moveSprites, true, 2.8),
      m_attack_distance(attack_distance),
      m_health(health) {
  setPosition(startPosition);
  m_sbuffer.loadFromFile(enemyHitSound);
  hitSound.setBuffer(m_sbuffer);
  hitSound.setPitch(2);
  hitSound.setVolume(40);
}

AnimatedGameObject &EyeEnemy::getEnemyObject() { return m_EyeEnemyObject; }

void EyeEnemy::hit(int damage) {
  if (isHitted && isDead) {
    return;
  }
  hitSound.setBuffer(m_sbuffer);
  hitSound.play();
  printf("Hit\n");
  isHitted = true;
  m_health -= damage;
  if (m_health <= 0) {
    m_EyeEnemyObject.resetAnimation();
    m_EyeEnemyObject.stopAtEnd = true;
    m_EyeEnemyObject.m_sprites_array = m_deathSprites;
    isDead = true;
  } else {
    m_EyeEnemyObject.m_sprites_array = m_takeDamageSprites;
  }
}

sf::FloatRect EyeEnemy::getNextPosition(sf::Time deltaTime,
                                        sf::Vector2f positionTowards) const {
  sf::Vector2f velocity = calculateTowardsVector(positionTowards);
  sf::FloatRect nextPosition(
      m_EyeEnemyObject.getPosition(),
      {m_EyeEnemyObject.m_sprite.getGlobalBounds().height *
           m_EyeEnemyObject.m_scale,
       m_EyeEnemyObject.m_sprite.getGlobalBounds().width *
           m_EyeEnemyObject.m_scale});
  nextPosition.top += velocity.y * deltaTime.asSeconds();
  nextPosition.left += velocity.x * deltaTime.asSeconds();
  return nextPosition;
}

sf::Vector2f EyeEnemy::calculateTowardsVector(sf::Vector2f position) const {
  sf::Vector2f moveTo = (position - m_EyeEnemyObject.getPosition());
  moveTo /= std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y);
  moveTo.x *= m_speed;
  moveTo.y *= m_speed;
  return moveTo;
}

void EyeEnemy::moveTowards(sf::Vector2f position, sf::Time deltaTime) {
  if (!isHitted && !isDead) {
    sf::Vector2f moveTo = (position - m_EyeEnemyObject.getPosition());
    if (std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y) <=
        m_attack_distance) {
      m_EyeEnemyObject.m_sprites_array = m_attackSprites;
    } else {
      m_EyeEnemyObject.m_sprites_array = m_moveSprites;
      moveTo /= std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y);
      move(moveTo * m_speed * deltaTime.asSeconds());
      m_EyeEnemyObject.move(moveTo * m_speed * deltaTime.asSeconds());
    }
  } else {
    if (m_EyeEnemyObject.isLastAnimationState()) isHitted = false;
  }
}

void EyeEnemy::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
  surface.draw(m_EyeEnemyObject);
}