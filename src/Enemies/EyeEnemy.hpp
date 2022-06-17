#pragma once
#include <SFML/Audio.hpp>

#include "../GameObject/AnimatedGameObject.hpp"
#include "cmath"

class EyeEnemy : public sf::Drawable, public sf::Transformable {
  AnimatedGameObject m_EyeEnemyObject;
  int m_health;
  int initial_health;
  float m_speed;
  float m_attack_distance;
  bool isHitted = false;
  bool isDead = false;
  sf::Vector2f m_velocity;
  std::vector<sf::Sprite> m_moveSprites;
  std::vector<sf::Sprite> m_attackSprites;
  std::vector<sf::Sprite> m_takeDamageSprites;
  std::vector<sf::Sprite> m_deathSprites;

  sf::SoundBuffer m_sbuffer;
  sf::Sound hitSound;

 public:
  EyeEnemy(sf::Vector2f startPosition, std::vector<sf::Sprite> moveSprites,
           std::vector<sf::Sprite> attackSprites,
           std::vector<sf::Sprite> takeDamageSprites,
           std::vector<sf::Sprite> deathSprites, float speed,
           float attack_distancde, std::string enemyHitSound, int health = 100);

  void moveTowards(sf::Vector2f position, sf::Time deltaTime);
  void hit(int damage);
  sf::Vector2f calculateTowardsVector(sf::Vector2f position) const;
  sf::FloatRect getNextPosition(sf::Time deltaTime,
                                sf::Vector2f positionTowards) const;
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
  AnimatedGameObject &getEnemyObject();
  bool getDead() const;
};
