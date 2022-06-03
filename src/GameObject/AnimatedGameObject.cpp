#include "AnimatedGameObject.hpp"

AnimatedGameObject::AnimatedGameObject()
    : m_cordinates({0, 0}), animation_state(0) {}
AnimatedGameObject::AnimatedGameObject(const sf::Vector2f &cordinates,
                                       std::vector<sf::Sprite> &sprites_array)
    : m_cordinates(cordinates),
      m_sprites_array(sprites_array),
      animation_state(0) {
  setPosition(m_cordinates);
}

void AnimatedGameObject::draw(sf::RenderTarget &surface,
                              sf::RenderStates states) const {
  states.transform *= getTransform();
  surface.draw(m_sprites_array[animation_state], states);
}

void AnimatedGameObject::nextState() {
  if (animation_state < m_sprites_array.size() - 1) {
    animation_state++;
  } else {
    animation_state = 0;
  }
}