#pragma once
#include <../GameObject/GameObject.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable {
	GameObject m_bulletObject;
	sf::Vector2f m_velocity;
	sf::Time m_lifetime;

  public:
	bool isExist = true;

	/**
	 * @brief Класс, пули
	 *
	 * @param startPosition начальное положение
	 * @param velocity вектор скорости
	 * @param bulletSprite спрайты пули
	 */
	Bullet(sf::Vector2f startPosition, sf::Vector2f velocity,
	       std::vector<sf::Sprite> bulletSprite);

	/**
	 * @brief Метод, возращающий GameObject пули
	 */
	GameObject &getBulletObject();

	/**
	 * @brief Метод, передвигающий пулю
	 *
	 * @param deltaTime deltaTime
	 */
	void moveBullet(sf::Time deltaTime);

	virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

	/**
	 * @brief Метод, возращающий FloatRect пули
	 */
	sf::FloatRect getBulletRect();
};
