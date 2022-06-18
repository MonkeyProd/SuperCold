#include "GameObject.hpp"

#include "../Utils/debug.hpp"

GameObject::GameObject() : m_cordinates({0, 0}), animation_state(0) {}
GameObject::GameObject(const sf::Vector2f &cordinates,
                       std::vector<sf::Sprite> &sprites_array, bool isCollider,
                       float scale, sf::Vector2f boxCollider)
    : m_cordinates(cordinates), m_sprites_array(sprites_array),
      animation_state(0), m_isCollider(isCollider), m_scale(scale),
      m_boxCollider(boxCollider) {
	m_sprite = m_sprites_array[0];
	setScale(scale, scale);
	setPosition(m_cordinates);
	isAnimated = true;
}

GameObject::GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite,
                       bool isCollider, float scale, sf::Vector2f boxCollider)
    : m_cordinates(cordinates), m_sprite(sprite), m_isCollider(isCollider),
      m_scale(scale), m_boxCollider(boxCollider) {
	setPosition(m_cordinates);
	setScale(scale, scale);
}

bool GameObject::isCollider() const { return m_isCollider; }

void GameObject::resetAnimation() { animation_state = 0; }

void GameObject::draw(sf::RenderTarget &surface,
                      sf::RenderStates states) const {
	states.transform *= getTransform();
	surface.draw(m_sprite, states);
}

bool GameObject::check_collision(GameObject &other) const {
	sf::FloatRect m_rect = getGameObjectRect();
	sf::FloatRect o_rect = other.getGameObjectRect();

	return m_rect.intersects(o_rect);
}

bool GameObject::check_collision(sf::FloatRect &otherFloatRect) const {
	sf::FloatRect m_rect = getGameObjectRect();
	return m_rect.intersects(otherFloatRect);
}

sf::FloatRect GameObject::getGameObjectRect() const {
	if (m_boxCollider == sf::Vector2f{0, 0})
		return {getPosition(),
		        {m_sprite.getGlobalBounds().height * m_scale,
		         m_sprite.getGlobalBounds().width * m_scale}};
	else
		return {{getPosition().x + m_sprite.getGlobalBounds().width / 2,
		         getPosition().y + m_sprite.getGlobalBounds().height / 2},
		        {m_boxCollider.x, m_boxCollider.y}};
}

void GameObject::nextState() {
	if (isAnimated && !isFinished) {
		if (animation_state < m_sprites_array.size() - 1) {
			animation_state++;
		} else {
			if (!stopAtEnd) {
				animation_state = 0;
			} else {
				isFinished = true;
			}
		}
		m_sprite = m_sprites_array[animation_state];
	}
}

bool GameObject::isLastAnimationState() const {
	return animation_state == m_sprites_array.size() - 1;
}