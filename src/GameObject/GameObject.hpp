#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.hpp"
/**
 * GameObject class
 * have animation state which says what sprite index use to draw
 */
class GameObject : public sf::Drawable, public sf::Transformable {
 private:
  sf::Vector2f m_cordinates;
  sf::Vector2f m_boxCollider;

  int animation_state;
  bool m_isCollider;
  bool isAnimated = false;
  bool isFinished = false;

 public:
  float m_scale;
  bool stopAtEnd = false;

  std::vector<sf::Sprite> m_sprites_array;
  sf::Sprite m_sprite;

  GameObject();
  GameObject(const sf::Vector2f &cordinates,
             std::vector<sf::Sprite> &sprites_array, bool isCollider = false,
             float scale = 1, sf::Vector2f boxCollider = {0, 0});

  GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite,
             bool isCollider = false, float scale = 1,
             sf::Vector2f boxCollider = {0, 0});

  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
  /**
   * nextState method change animation state to next one if animation ended it
   * starts from begining
   */
  void nextState();
  bool isCollider() const;

  void resetAnimation();

  bool check_collision(GameObject &other) const;
  bool check_collision(sf::FloatRect &otherFloatRect) const;
  sf::FloatRect getGameObjectRect() const;

  bool isLastAnimationState() {
    if (animation_state == m_sprites_array.size() - 1) {
      return true;
    }
    return false;
  }
};