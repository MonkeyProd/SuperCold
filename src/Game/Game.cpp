#include "Game.hpp"

#include "cmath"
using std::atan2;
Game::Game(unsigned int h, unsigned int w)
    : WINDOW_SIZE_H(h), WINDOW_SIZE_W(w),
      window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
                              "SuperCold",
                              sf::Style::Titlebar | sf::Style::Close)),
      FPS{60}, paused{false},
      camera(sf::FloatRect(0, 0, WINDOW_SIZE_W, WINDOW_SIZE_H)),
      map(sf::FloatRect(0, 0, WINDOW_SIZE_W * 2, WINDOW_SIZE_H * 2)),
      settingsManager(), difficulty(1) {
	spriteController = SpriteController(settingsManager);
	player = Player(
	    {0, 100}, {0, 0}, spriteController.playerSprites,
	    toml::find<std::string>(settingsManager.SoundSettings, "footsteps"));
	auto sprites = spriteController.spriteArrays["world"];
	previousPlayerPosition = sf::Vector2i(player.getPlayerPosition() / 64.0f);
	draw_world(sprites);
}

void Game::shootBullet(sf::Vector2f velocity) {
	bulletLayer.push_back(
	    Bullet{{player.get_playerObject().getPosition().x,
	            player.get_playerObject().getPosition().y + 40},
	           velocity,
	           spriteController.spriteArrays["simple_bullet"]});
}

void Game::ProcessEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (not paused) {
			auto W{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)};
			auto S{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)};
			auto A{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)};
			auto D{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)};
			auto Q{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)};
			auto Up{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)};
			auto Down{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)};
			auto Left{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)};
			auto Right{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)};
			auto LShift{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)};
			auto Space{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)};
			if (Up)
				shootBullet({0, -200});
			if (Down)
				shootBullet({0, 200});
			if (Left)
				shootBullet({-200, 0});
			if (Right)
				shootBullet({200, 0});
			if (Q)
				window.close();
			if (W)
				player.changeYDirection(Player::VerticalDirection::Top);
			if (A)
				player.changeXDirection(Player::HorizontalDirection::Left);
			if (S)
				player.changeYDirection(Player::VerticalDirection::Down);
			if (D)
				player.changeXDirection(Player::HorizontalDirection::Right);
			if (W and S)
				player.resetVerticalVelocity();
			if (A and D)
				player.resetHorizontalVelocity();
			if (not(W or S))
				player.resetVerticalVelocity();
			if (not(A or D))
				player.resetHorizontalVelocity();
			if (Space)
				paused = !paused;
			if (LShift)
				player.setSpeed(settingsManager.get<float>(
				    settingsManager.PlayerSettings, "run_speed"));
			if (not LShift)
				player.setSpeed(settingsManager.get<float>(
				    settingsManager.PlayerSettings, "speed"));
		}
	}
}
/**
 * There animation state of each object in animatedLayer is changing
 */
void Game::update(sf::Time deltatime) {
	camera.setCenter(player.get_playerObject().getPosition());
	map.setCenter(player.get_playerObject().getPosition());
	bool canMove = true;
	sf::FloatRect playerNextPosition = player.getNextPosition(deltatime);
	for (auto &object : drawLayer) {
		if (object.isCollider() && object.check_collision(playerNextPosition)) {
			canMove = false;
			break;
		}
	}
	if (canMove)
		player.movePlayer(deltatime);

	auto attack_distance =
	    toml::find<float>(settingsManager.EnemySettings, "attack_distance");
	for (auto &object : enemies) {
		bool canEnemyMove = true;
		sf::FloatRect enemyRect = object.getNextPosition(
		    deltatime, player.get_playerObject().getPosition());
		sf::Vector2f toPlayer = (player.get_playerObject().getPosition() -
		                         object.getEnemyObject().getPosition());
		auto dist_sq = toPlayer.x * toPlayer.x + toPlayer.y * toPlayer.y;
		auto dist = std::sqrt(dist_sq);
		if (dist < attack_distance and object.canAttack()) {
			player.getHit(difficulty * 3);
			object.attacked();
		}
		for (auto &object_t : enemies) {
			if (&object != &object_t and (not object_t.getDead())) {
				if (object_t.getEnemyObject().check_collision(enemyRect)) {
					canEnemyMove = false;
					break;
				}
			}
		}
		if (canEnemyMove)
			object.moveTowards(player.get_playerObject().getPosition(),
			                   deltatime);
	}

	for (auto &bullet : bulletLayer) {
		bool isCollided = false;
		sf::FloatRect bulletRect = bullet.getBulletRect();
		for (auto &object : drawLayer) {
			if (object.isCollider() && object.check_collision(bulletRect)) {
				isCollided = true;
				break;
			}
		}
		if (!isCollided && bullet.isExist)
			bullet.moveBullet(deltatime);
		else {
			bullet.isExist = false;
		}
	}

	for (auto &bullet : bulletLayer) {
		bool isCollided = false;
		sf::FloatRect bulletRect = bullet.getBulletRect();
		for (auto &object : enemies) {
			if (bullet.isExist and (not object.getDead()) and
			    object.getEnemyObject().check_collision(bulletRect)) {
				object.hit(25);
				bullet.isExist = false;

				// check if all enemies killed
				auto alive_number =
				    std::count_if(enemies.cbegin(), enemies.cend(),
				                  [](EyeEnemy e) { return not e.getDead(); });
				if (alive_number == 0) {
					difficulty *= 2;
					new_wave();
				}
				break;
			}
		}
	}

	bulletLayer.erase(std::remove_if(bulletLayer.begin(), bulletLayer.end(),
	                                 [](Bullet &b) { return not b.isExist; }),
	                  bulletLayer.end());

	sf::Vector2i currentPlayerPos(player.getPlayerPosition());
	currentPlayerPos /= 64;
	auto delta = currentPlayerPos - previousPlayerPosition;
	if (fabs(delta.x) > 1.0f or fabs(delta.y) > 1.0f) {
		auto sprites = spriteController.spriteArrays["world"];
		drawLayer.clear();
		previousPlayerPosition =
		    sf::Vector2i(player.getPlayerPosition() / 64.0f);
		draw_world(sprites);
	}
}

void Game::updateAnimations(sf::Time deltatime) {
	for (auto &object : drawLayer) {
		object.nextState();
	}
	for (auto &object : bulletLayer) {
		object.getBulletObject().nextState();
	}
	for (auto &object : enemies) {
		object.getEnemyObject().nextState();
	}
	player.nextState();
}

/**
 * Drawing all layers
 */
void Game::draw(sf::Time deltaTime) {
	if (paused)
		window.setView(map);
	else
		window.setView(camera);
	window.clear(sf::Color(16, 0, 41));

	for (auto &object : drawLayer) {
		window.draw(object);
	}

	for (auto &object : enemies) {
		window.draw(object);
	}
	window.draw(player);
	for (auto &object : bulletLayer) {
		if (object.isExist)
			window.draw(object);
	}
	window.display();
}

void Game::run() {
	sf::SoundBuffer buffer;
	buffer.loadFromFile(
	    toml::find<std::string>(settingsManager.SoundSettings, "bg_music"));
	sf::Sound bg_music;
	bg_music.setBuffer(buffer);
	bg_music.setVolume(10);
	bg_music.play();

	window.setMouseCursorVisible(false);
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS);
	sf::Time timePerAnimation = sf::seconds(1.0f / 10);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timeSinceLastAnimation = sf::Time::Zero;

	new_wave();

	while (window.isOpen()) {
		auto deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;
		timeSinceLastAnimation += deltaTime;
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents();
			if (not paused) {
				update(timePerFrame);
			}
		}
		while (timeSinceLastAnimation > timePerAnimation) {
			timeSinceLastAnimation -= timePerAnimation;
			if (not paused) {
				updateAnimations(timePerAnimation);
			}
		}
		draw(deltaTime);
	}
}

/**
 * @brief Генерация и отрисовка игрового мира в области вокруг игрока
 *
 * @param sprites спрайты игрового мира
 */
void Game::draw_world(std::vector<sf::Sprite> sprites) {
	toml::find<float>(settingsManager.WorldGenSettings, "frequency");

	auto size{64};
	float frequency =
	    toml::find<float>(settingsManager.WorldGenSettings, "frequency");
	float amplitude =
	    toml::find<float>(settingsManager.WorldGenSettings, "amplitude");
	sf::Vector2f cord(sf::Mouse::getPosition());
	cord.x /= WINDOW_SIZE_W;
	cord.y /= WINDOW_SIZE_H;
	float lacunarity =
	    toml::find<float>(settingsManager.WorldGenSettings, "lacunarity");
	float persistence = 1 / lacunarity;
	SimplexNoise n(frequency, amplitude, lacunarity, persistence);
	sf::View currentView = window.getView();
	int genWidth{static_cast<int>(currentView.getSize().x / size + 5)};
	int genHeight{static_cast<int>(currentView.getSize().y / size + 5)};
	for (int i = -genWidth; i < genWidth; i++) {
		for (int j = -genHeight; j < genHeight; j++) {
			auto x{i + previousPlayerPosition.x};
			auto y{j + previousPlayerPosition.y};
			auto sample = n.fractal(7, x, y);
			auto normalized = (sample + 1.0f) * 0.5f * 255.0f;
			sf::RectangleShape rectt(sf::Vector2f(size, size));
			rectt.setPosition(i * size, j * size);
			rectt.setFillColor(sf::Color(0, 0, 255));
			auto floor_start{150};
			auto floor_end{170};

			GameObject tile;
			if (floor_start < normalized && normalized < floor_end) {
				rectt.setFillColor(sf::Color(255, 0, 0)); // wall
				tile = {sf::Vector2f(x * size, y * size),
				        spriteController.spriteObjects["wall"],
				        true,
				        8,
				        {60, 60}};
				drawLayer.push_back(tile);
			} else if (normalized > floor_end) {
				rectt.setFillColor(sf::Color(0, 250, 0)); // floor
				tile = {sf::Vector2f(x * size, y * size),
				        spriteController.spriteObjects["floor"],
				        false,
				        8,
				        {60, 60}};
				drawLayer.push_back(tile);
			}
		}
	}
}

void Game::new_wave() {
	enemies.clear();
	player.resetHealth();
	auto speed = toml::find<float>(settingsManager.EnemySettings, "speed");
	auto attack_distance =
	    toml::find<float>(settingsManager.EnemySettings, "attack_distance");
	for (int i = 0; i < difficulty; i++) {
		EyeEnemy enemy(
		    {(float)(rand() % 1300) + 200, (float)(rand() % 1300) + 200},
		    spriteController.spriteArrays["enemy_move"],
		    spriteController.spriteArrays["enemy_attack"],
		    spriteController.spriteArrays["enemy_hit"],
		    spriteController.spriteArrays["enemy_death"], speed,
		    attack_distance,
		    toml::find<std::string>(settingsManager.SoundSettings, "enemy_hit"),
		    difficulty * 30);

		enemies.push_back(enemy);
	}
}
