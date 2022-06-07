#include "GameObject.hpp"

GameObject::GameObject() : m_cordinates({0.0f, 0.0f}), m_sprite() {}

GameObject::GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite,
                       bool isCollider, float scale)
    : m_cordinates(cordinates),
      m_sprite(sprite),
      m_isCollider(isCollider),
      m_scale(scale) {
  setPosition(m_cordinates);
  setScale(scale, scale);
}

bool GameObject::isCollider() { return m_isCollider; }

void GameObject::draw(sf::RenderTarget &surface,
                      sf::RenderStates states) const {
  states.transform *= getTransform();
  surface.draw(m_sprite, states);
}

bool GameObject::check_collision(GameObject &other) {
  sf::FloatRect m_rect(getPosition(),
                       {m_sprite.getGlobalBounds().height * m_scale,
                        m_sprite.getGlobalBounds().width * m_scale});
  sf::FloatRect o_rect(
      other.getPosition(),
      {other.m_sprite.getGlobalBounds().height * other.m_scale,
       other.m_sprite.getGlobalBounds().width * other.m_scale});

  printf("%f %f\n", m_sprite.getGlobalBounds().height,
         m_sprite.getGlobalBounds().width);
  printf("%f %f\n", o_rect.left, o_rect.top);
  return m_rect.intersects(o_rect);
}
