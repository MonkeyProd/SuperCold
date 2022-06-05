#include "AnimatedGameObject.hpp"

AnimatedGameObject::AnimatedGameObject()
    : m_cordinates({0, 0}), animation_state(0) {}
AnimatedGameObject::AnimatedGameObject(const sf::Vector2f &cordinates,
                                       std::vector<sf::Sprite> &sprites_array,
                                       bool isCollider, float scale)
    : m_cordinates(cordinates),
      m_sprites_array(sprites_array),
      animation_state(0),
      m_isCollider(isCollider),
      m_scale(scale) {
  m_sprite = m_sprites_array[0];
  setScale(scale, scale);
  setPosition(m_cordinates);
}

void AnimatedGameObject::draw(sf::RenderTarget &surface,
                              sf::RenderStates states) const {
  states.transform *= getTransform();
  surface.draw(m_sprite, states);
}

void AnimatedGameObject::flip() {
  for (auto &sprite : m_sprites_array) {
    sprite.setOrigin({sprite.getLocalBounds().width, 0});
    sprite.scale({-1, 1});
  }
}

void AnimatedGameObject::nextState() {
  if (animation_state < m_sprites_array.size() - 1) {
    animation_state++;
  } else {
    animation_state = 0;
  }
  m_sprite = m_sprites_array[animation_state];
}