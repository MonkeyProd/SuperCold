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
  std::vector<sf::Sprite> m_sprites_array;
  int animation_state;

 public:
  AnimatedGameObject();
  AnimatedGameObject(const sf::Vector2f &cordinates,
                     std::vector<sf::Sprite> &sprites_array);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
  /**
   * nextState method change animation state to next one if animation ended it
   * starts from begining
   */
  void nextState();
  void flip();
};