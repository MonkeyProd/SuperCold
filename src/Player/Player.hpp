#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../GameObject/GameObject.hpp"
#include "../SpriteContoller/SpriteController.hpp"

class Player : public sf::Drawable, public sf::Transformable {
  using spritesMap = std::map<std::string, std::vector<sf::Sprite>>;

  sf::Vector2f m_velocity;
  sf::Vector2f m_position;

  std::map<std::string, std::vector<sf::Sprite>> m_playerSprites;

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
  enum HorizontalDirection { Left, Right };
  enum VerticalDirection { Top, Down };
  Player() = default;
  Player(sf::Vector2f startPosition, sf::Vector2f velocity,
         spritesMap playerSprites, std::string footsteps_path,
         float speed = 100, int health = 100);

  void changeXDirection(HorizontalDirection direction);
  void changeYDirection(VerticalDirection direction);

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
