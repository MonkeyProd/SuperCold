#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.hpp"
/**
 * GameObject class
 * have animation state which says what sprite index use to draw
 */
class GameObject : public sf::Drawable, public sf::Transformable {
  private:
	sf::Vector2f m_cordinates;
	sf::Vector2f m_boxCollider;

	int animation_state;
	bool m_isCollider;
	bool isAnimated = false;
	bool isFinished = false;

  public:
	float m_scale;
	bool stopAtEnd = false;

	std::vector<sf::Sprite> m_sprites_array;
	sf::Sprite m_sprite;

	GameObject();
	/**
	 * @brief Класс игрового объекта
	 *
	 * @param cordinates положение игрвого объекта
	 * @param sprites_array вектор спрайтов(для анимации)
	 * @param isCollider bool - является ли игровой объект коллайдером
	 * @param scale коэффициент увеличения спрайта игрового объекта
	 * @param boxCollider размеры квадрата коллизии игрового объекта
	 */
	GameObject(const sf::Vector2f &cordinates,
	           std::vector<sf::Sprite> &sprites_array, bool isCollider = false,
	           float scale = 1, sf::Vector2f boxCollider = {0, 0});

	/**
	 * @brief Класс игрового объекта
	 *
	 * @param cordinates положение игрвого объекта
	 * @param sprite спрайт игрового объекта
	 * @param isCollider bool - является ли игровой объект коллайдером
	 * @param scale коэффициент увеличения спрайта игрового объекта
	 * @param boxCollider размеры квадрата коллизии игрового объекта
	 */
	GameObject(const sf::Vector2f &cordinates, const sf::Sprite &sprite,
	           bool isCollider = false, float scale = 1,
	           sf::Vector2f boxCollider = {0, 0});

	virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

	/**
	 * @brief Метод меняющий спрайт анимации игрового объекта на следующий
	 */
	void nextState();

	/**
	 * @brief Метод, возращающий bool - является ли игровой объекта коллайдером
	 * @return true является
	 * @return false не является
	 */
	bool isCollider() const;

	/**
	 * @brief Метод сброса анимации до начального спрайта
	 */
	void resetAnimation();

	/**
	 * @brief Метод, возрающий bool - пересеклись ли два игровых объекта
	 *
	 * @param other игровой объект с которым проверяем пересечение
	 * @return true есть пересечение
	 * @return false нет пересечения
	 */
	bool check_collision(GameObject &other) const;

	/**
	 * @brief Метод, возрающий bool - пересеклись ли игровой объект и FloatRect
	 *
	 * @param otherFloatRect FloatRect с которым проверяем пересечение
	 * @return true пересечение есть
	 * @return false пересечения нет
	 */
	bool check_collision(sf::FloatRect &otherFloatRect) const;

	/**
	 * @brief Метод, возрающий FloatRect игрового объекта
	 *
	 * @return sf::FloatRect
	 */
	sf::FloatRect getGameObjectRect() const;

	/**
	 * @brief  Метод, возрающий bool - является ли текущий спрайт последним в
	 * анимации
	 *
	 * @return true да, является
	 * @return false нет, не является
	 */
	bool isLastAnimationState() const;
};
