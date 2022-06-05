#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable, public sf::Transformable {
 private:
  sf::Vector2f m_cordinates;
  bool m_isCollider;

 public:
  sf::Sprite m_sprite;
  float m_scale;

  GameObject();
  GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite,
             bool isCollider = false, float scale = 1);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
  bool check_collision(GameObject &other);
};
