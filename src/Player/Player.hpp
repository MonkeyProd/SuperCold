#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../GameObject/GameObject.hpp"
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

  sf::SoundBuffer m_sbuffer;
  sf::Sound m_footstepsSound;

  GameObject m_playerObject;
  float m_speed;
  bool isLookRight;
  bool isMoveHorizontal = false;
  bool isMoveVertical = false;
  bool isStepping = false;
  int health;
  int initial_health;

 public:
  Player() = default;
  Player(sf::Vector2f startPosition, sf::Vector2f velocity,
         std::vector<sf::Sprite> playerRunForward,
         std::vector<sf::Sprite> playerRunBack,
         std::vector<sf::Sprite> playerRunLeft,
         std::vector<sf::Sprite> playerRunRight,
         std::vector<sf::Sprite> playerForward,
         std::vector<sf::Sprite> playerBack, std::vector<sf::Sprite> playerLeft,
         std::vector<sf::Sprite> playerRight, std::string footsteps_path,
         float speed = 100, int health = 100);

  void moveLeft();
  void moveRight();
  void moveTop();
  void moveDown();

  void resetHorizontalVelocity();
  void resetVerticalVelocity();

  void movePlayer(sf::Time deltaTime);

  void setSpeed(float speed);
  bool isDead() const;
  void resetHealth();

  sf::Vector2f getPlayerPosition() const;
  sf::Vector2f getPlayerVelocity() const;
  sf::FloatRect getNextPosition(sf::Time deltaTime) const;

  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

  GameObject &get_playerObject();
};
