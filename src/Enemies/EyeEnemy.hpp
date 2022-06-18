#pragma once
#include <SFML/Audio.hpp>

#include "../GameObject/GameObject.hpp"
#include "cmath"
#include <../external/PriorityQueue/PriorityQueue.hpp>
#include <algorithm>
#include <map>

class EyeEnemy : public sf::Drawable, public sf::Transformable {
	GameObject m_EyeEnemyObject;
	int m_health;
	int initial_health;
	float m_speed;
	float m_attack_distance;
	bool isHitted = false;
	bool isDead = false;
	sf::Time attackTime;
	bool m_canAttack;
	sf::Vector2f m_velocity;
	std::vector<sf::Sprite> m_moveSprites;
	std::vector<sf::Sprite> m_attackSprites;
	std::vector<sf::Sprite> m_takeDamageSprites;
	std::vector<sf::Sprite> m_deathSprites;

	sf::SoundBuffer m_sbuffer;
	sf::Sound hitSound;

  public:
	/**
	 * @brief Враг - летающий глаз
	 *
	 * @param startPosition начальное положение
	 * @param moveSprites спрайты движения
	 * @param attackSprites спрайты атаки
	 * @param takeDamageSprites спрайты получения урона
	 * @param deathSprites спрайты смерти
	 * @param speed скорость передвижения
	 * @param attack_distance дистанция с которой начинается атака
	 * @param enemyHitSound название звука получения урона
	 * @param health начальное здоровье
	 */
	EyeEnemy(sf::Vector2f startPosition, std::vector<sf::Sprite> moveSprites,
	         std::vector<sf::Sprite> attackSprites,
	         std::vector<sf::Sprite> takeDamageSprites,
	         std::vector<sf::Sprite> deathSprites, float speed,
	         float attack_distance, std::string enemyHitSound,
	         int health = 100);

	/**
	 * @brief Метод передвигающий врага
	 *
	 * @param position положение куда передвигаться
	 * @param deltaTime deltaTime
	 */
	void moveTowards(sf::Vector2f position, sf::Time deltaTime);

	/**
	 * @brief Метод получения урона
	 *
	 * @param damage количество полученного урона
	 */
	void hit(int damage);

	/**
	 * @brief Метод расчета вектора траектории к положению
	 *
	 * @param position положение к которому рассчитывается траектория
	 */
	sf::Vector2f calculateTowardsVector(sf::Vector2f position) const;

	/**
	 * @brief Метод расчета положения врага в следующий момент времени (нужен
	 * для коллизии)
	 *
	 * @param deltaTime deltaTime
	 * @param positionTowards положение к которому движется враг
	 */
	sf::FloatRect getNextPosition(sf::Time deltaTime,
	                              sf::Vector2f positionTowards) const;

	virtual void draw(sf::RenderTarget &surface, sf::RenderStates states) const;
	/**
	 * @brief Метод возращающий GameObject врага
	 */
	GameObject &getEnemyObject();
	/**
	 * @brief Метод возращающий статус смерти врага
	 */
	bool getDead() const;

	/**
	 * @brief проверка возможности атаковать
	 *
	 * @return true атака возможна
	 * @return false атака невозможна
	 */
	bool canAttack() const;

	void attacked();
};
