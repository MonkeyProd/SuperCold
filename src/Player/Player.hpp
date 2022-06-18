#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../GameObject/GameObject.hpp"
#include "../SpriteContoller/SpriteController.hpp"

class Player : public sf::Drawable, public sf::Transformable {
	using spritesMap = std::map<std::string, std::vector<sf::Sprite>>;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;

	std::map<std::string, std::vector<sf::Sprite>> m_playerSprites;

	std::vector<sf::Sprite> m_current_state;

	sf::SoundBuffer m_sbuffer;
	sf::Sound m_footstepsSound;

	mutable GameObject m_playerObject;
	float m_speed;
	bool isLookRight;
	bool isMoveHorizontal = false;
	bool isMoveVertical = false;
	bool isStepping = false;
	int health;
	int initial_health;
	mutable bool getting_hit;

  public:
	enum HorizontalDirection { Left, Right };
	enum VerticalDirection { Top, Down };
	Player() = default;

	/**
	 * @brief Класс Игрока
	 *
	 * @param startPosition начальное положение
	 * @param velocity начальный вектор скорости
	 * @param playerSprites словарь со всеми спрайтами игрока
	 * @param footsteps_path название аудио с звуком шагов
	 * @param speed скорость игрока
	 * @param health количество здоровья игрока
	 */
	Player(sf::Vector2f startPosition, sf::Vector2f velocity,
	       spritesMap playerSprites, std::string footsteps_path,
	       float speed = 100, int health = 100);

	/**
	 * @brief Метод, меняющий горизонатальную составляющую скорости игрока
	 *
	 * @param direction направление изменения скорости
	 */
	void changeXDirection(HorizontalDirection direction);

	/**
	 * @brief Метод, меняющий вертикальную составляющую скорости игрока
	 *
	 * @param direction направление изменения скорости
	 */
	void changeYDirection(VerticalDirection direction);

	/**
	 * @brief Метод, сбрасывающий горизонтальную состовляющую скорости игрока
	 */
	void resetHorizontalVelocity();

	/**
	 * @brief Метод, сбрасывающий вертикальную состовляющую скорости игрока
	 */
	void resetVerticalVelocity();

	/**
	 * @brief Метод, перемещающий игрока
	 * @param deltaTime deltaTime
	 */
	void movePlayer(sf::Time deltaTime);

	/**
	 * @brief Метод, изменяющий скорость игрока
	 * @param speed новая скорость
	 */
	void setSpeed(float speed);

	/**
	 * @brief Метод, возращающий bool - статус смерти игрока
	 *
	 * @return true мертв
	 * @return false жив
	 */
	bool isDead() const;

	/**
	 * @brief Метод, восстанавливающий исходное здровье игрока
	 */
	void resetHealth();

	/**
	 * @brief Метод, возращающий положение игрока
	 * @return sf::Vector2f позиция
	 */
	sf::Vector2f getPlayerPosition() const;

	/**
	 * @brief Метод, возращающий скорость игрока
	 * @return sf::Vector2f скорость
	 */
	sf::Vector2f getPlayerVelocity() const;

	/**
	 * @brief Метод, возращающий FloatRect - положение игрока в следующий момент
	 * времени(необходим для проверки коллизии)
	 * @param deltaTime deltaTime
	 * @return sf::FloatRect
	 */
	sf::FloatRect getNextPosition(sf::Time deltaTime) const;

	/**
	 * @brief отрисовка игрока на поверхность
	 *
	 * @param surface поверхность
	 * @param states состояние
	 */
	virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;

	/**
	 * @brief
	 */

	/**
	 * @brief Метод, возращающий GameObject игрока
	 *
	 * @return GameObject&
	 */
	GameObject &get_playerObject();

	/**
	 * @brief Нанести урон игроку
	 *
	 * @param hp количество урона
	 */
	void getHit(int hp);

	/**
	 * @brief Метод меняющий спрайт анимации игрока на следующий
	 */
	void nextState();
};
