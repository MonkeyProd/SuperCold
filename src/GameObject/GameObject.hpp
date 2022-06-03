#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable, public sf::Transformable {
 private:
  sf::Vector2f m_cordinates;
  sf::Sprite m_sprite;

 public:
  GameObject();
  GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite);
  virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
};
