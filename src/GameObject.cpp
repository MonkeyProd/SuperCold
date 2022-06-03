#include "GameObject.hpp"

GameObject::GameObject() : m_cordinates({0.0f, 0.0f}), m_sprite()
{
}

GameObject::GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite)
	: m_cordinates(cordinates), m_sprite(sprite)
{
}

void GameObject::draw(sf::RenderTarget &surface)
{
	m_sprite.setPosition(m_cordinates);
	surface.draw(m_sprite);
}
