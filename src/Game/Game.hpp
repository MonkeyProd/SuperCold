#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

#include "../Bullet/Bullet.hpp"
#include "../Enemies/EyeEnemy.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Player/Player.hpp"
#include "../SettingsManager/SettingsManager.hpp"
#include "../SpriteContoller/SpriteController.hpp"
#include "../TileMap/TileMap.hpp"
#include "../external/SimplexNoise/SimplexNoise.hpp"

class Game {
  private:
	unsigned int WINDOW_SIZE_H;
	unsigned int WINDOW_SIZE_W;
	uint8_t FPS;
	bool paused;

	sf::RenderWindow window;

	SpriteController spriteController;
	SettingsManager settingsManager;

	Player player;
	sf::Vector2i previousPlayerPosition;
	sf::View camera;
	sf::View map;

	std::vector<GameObject> drawLayer;
	std::vector<Bullet> bulletLayer;

	// TEMP
	std::vector<EyeEnemy> enemies;
	unsigned int difficulty;

	/**
	 * @brief обработка событиый
	 *
	 */
	void ProcessEvents();

	/**
	 * @brief обновлеине внутриигровых сущностей
	 *
	 * @param deltatime прошедшее время
	 */
	void update(sf::Time deltatime);

	/**
	 * @brief обновление анимаций внутриигровых сущностей
	 *
	 * @param deltatime прошедшее время
	 */
	void updateAnimations(sf::Time deltatime);

	/**
	 * @brief отрисовка внутриигровых сущностей на экран
	 *
	 * @param deltaTime прошедшее время
	 */
	void draw(sf::Time deltaTime);

	/**
	 * @brief генерация мира вокруг игрока
	 *
	 * @param sprites спрайты мира
	 */
	void draw_world(std::vector<sf::Sprite> sprites);

	/**
	 * @brief создание тестовой комнаты
	 *
	 * @param sprites спрайты мира
	 */
	void draw_test_room(std::vector<sf::Sprite> sprites);

	/**
	 * @brief отрисовка анимированного игрока
	 *
	 * @param sprites спрайты игрока
	 * @param x позиция по X
	 * @param y позиция по Y
	 */
	void draw_animated_player(std::vector<sf::Sprite> sprites, float x,
	                          float y);

	/**
	 * @brief запуск новой волны монстров, восстановление игрока
	 *
	 */
	void new_wave();

	//Механики
	/**
	 * @brief выстрелить пулей
	 *
	 * @param velocity скорость пули
	 */
	void shootBullet(sf::Vector2f velocity);

  public:
	/**
	 * @brief создать объект Игры, с окном с указанными размерами
	 *
	 * @param h высота окна
	 * @param w ширина окна
	 */
	Game(unsigned int h = 600U, unsigned int w = 800U);

	/**
	 * @brief запустить игру
	 *
	 */
	void run();
};
