#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.hpp"
/**
 * AnimatedGameObject class
 * have animation state which says what sprite index use to draw
 */
class AnimatedGameObject : public GameObject {
 private:
  sf::Vector2f m_cordinates;
  int animation_state;
  bool m_isCollider;

 public:
  float m_scale;
  std::vector<sf::Sprite> m_sprites_array;
  sf::Sprite m_sprite;

  AnimatedGameObject();
  AnimatedGameObject(const sf::Vector2f &cordinates,
                     std::vector<sf::Sprite> &sprites_array,
                     bool isCollider = false, float scale = 1);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
  /**
   * nextState method change animation state to next one if animation ended it
   * starts from begining
   */
  void nextState();
  void flip();
  bool check_collision(GameObject &other) {
    sf::FloatRect m_rect(getPosition(),
                         {m_sprite.getGlobalBounds().height * m_scale,
                          m_sprite.getGlobalBounds().width * m_scale});
    sf::FloatRect o_rect(
        other.getPosition(),
        {other.m_sprite.getGlobalBounds().height * other.m_scale,
         other.m_sprite.getGlobalBounds().width * other.m_scale});

    return m_rect.intersects(o_rect);
  }
};