#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
private:
	sf::Vector2f m_cordinates;
	sf::Sprite m_sprite;

public:
	GameObject();
	GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite);
	void draw(sf::RenderTarget &surface);
};
