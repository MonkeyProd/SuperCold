#include "GameObject.hpp"

GameObject::GameObject() : m_cordinates({0.0f, 0.0f}), m_sprite() {}

GameObject::GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite)
    : m_cordinates(cordinates), m_sprite(sprite) {
  setPosition(m_cordinates);
}

void GameObject::draw(sf::RenderTarget &surface,
                      sf::RenderStates states) const {
  states.transform *= getTransform();
  surface.draw(m_sprite, states);
}
