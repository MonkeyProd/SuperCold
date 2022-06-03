#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.hpp"
class AnimatedGameObject : public GameObject {
 private:
  sf::Vector2f m_cordinates;
  std::vector<sf::Sprite> m_sprites_array;
  int animation_state;

 public:
  AnimatedGameObject();
  AnimatedGameObject(const sf::Vector2f &cordinates,
                     std::vector<sf::Sprite> &sprites_array);
  void nextState();
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
};