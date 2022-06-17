#include "Game.hpp"

#include "cmath"
using std::atan2;
Game::Game(unsigned int h, unsigned int w)
	: WINDOW_SIZE_H(h),
	  WINDOW_SIZE_W(w),
	  window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
							  "SuperCold",
							  sf::Style::Titlebar | sf::Style::Close)),
	  FPS{60},
	  paused{false},
	  camera(sf::FloatRect(0, 0, WINDOW_SIZE_W, WINDOW_SIZE_H)),
	  map(sf::FloatRect(0, 0, WINDOW_SIZE_W * 2, WINDOW_SIZE_H * 2)),
	  settingsManager(),
	  difficulty(1)
{
	spriteController = SpriteController(settingsManager);
	player = Player(
		{0, 0}, {0, 0}, spriteController.spriteArrays["player_run_forward"],
		spriteController.spriteArrays["player_run_back"],
		spriteController.spriteArrays["player_run_left"],
		spriteController.spriteArrays["player_run_right"],
		spriteController.spriteArrays["player_forward"],
		spriteController.spriteArrays["player_back"],
		spriteController.spriteArrays["player_left"],
		spriteController.spriteArrays["player_right"],
		toml::find<std::string>(settingsManager.SoundSettings, "footsteps"));
	auto sprites = spriteController.spriteArrays["world"];
	previousPlayerPosition = sf::Vector2i(player.getPlayerPosition() / 64.0f);
	draw_world(sprites);
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Q:
			{
				window.close();
				break;
			}
			case sf::Keyboard::Space:
			{
				paused = !paused;
				break;
			}
			case sf::Keyboard::Left:
			{
				bulletLayer.push_back(
					Bullet{{player.get_playerObject().getPosition().x,
							player.get_playerObject().getPosition().y + 40},
						   {-200, 0},
						   spriteController.spriteArrays["simple_bullet"],
						   Bullet::BulletSide::Left});
				break;
			}
			case sf::Keyboard::Right:
			{
				bulletLayer.push_back(
					Bullet{{player.get_playerObject().getPosition().x,
							player.get_playerObject().getPosition().y + 40},
						   {200, 0},
						   spriteController.spriteArrays["simple_bullet"],
						   Bullet::BulletSide::Right});
				break;
			}
			case sf::Keyboard::Up:
			{
				bulletLayer.push_back(
					Bullet{{player.get_playerObject().getPosition().x + 20,
							player.get_playerObject().getPosition().y},
						   {0, -200},
						   spriteController.spriteArrays["simple_bullet"],
						   Bullet::BulletSide::Up});
				break;
			}
			case sf::Keyboard::Down:
			{
				bulletLayer.push_back(
					Bullet{{player.get_playerObject().getPosition().x + 40,
							player.get_playerObject().getPosition().y},
						   {0, 200},
						   spriteController.spriteArrays["simple_bullet"],
						   Bullet::BulletSide::Down});
				break;
			}
			case sf::Keyboard::LShift:
			{
				player.setSpeed(settingsManager.get<float>(
					settingsManager.PlayerSettings, "run_speed"));
				break;
			}
			default:
				break;
			}
			break;
		}
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::LShift:
			{
				player.setSpeed(settingsManager.get<float>(
					settingsManager.PlayerSettings, "speed"));
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	if (not paused)
	{
		auto Top{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)};
		auto Down{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)};
		auto Left{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)};
		auto Right{sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)};
		if (Top)
			player.moveTop();
		if (Left)
			player.moveLeft();
		if (Down)
			player.moveDown();
		if (Right)
			player.moveRight();
		if (Top and Down)
			player.resetVerticalVelocity();
		if (Left and Right)
			player.resetHorizontalVelocity();
		if (not(Top or Down))
			player.resetVerticalVelocity();
		if (not(Left or Right))
			player.resetHorizontalVelocity();
	}
}

/**
 * There animation state of each object in animatedLayer is changing
 */
void Game::update(sf::Time deltatime)
{
	camera.setCenter(player.get_playerObject().getPosition());
	map.setCenter(player.get_playerObject().getPosition());
	bool canMove = true;
	sf::FloatRect playerNextPosition = player.getNextPosition(deltatime);
	for (auto &object : drawLayer)
	{
		if (object.isCollider() && object.check_collision(playerNextPosition))
		{
			canMove = false;
			break;
		}
	}
	if (canMove)
		player.movePlayer(deltatime);

	for (auto &object : enemies)
	{
		bool canEnemyMove = true;
		sf::FloatRect enemyRect = player.getNextPosition(deltatime);
		for (auto &object_t : enemies)
		{
			if (&object != &object_t)
				if (object_t.getEnemyObject().check_collision(enemyRect))
				{
					canEnemyMove = false;
					break;
				}
		}
		if (canEnemyMove)
			object.moveTowards(player.get_playerObject().getPosition(), deltatime);
	}

	for (auto &bullet : bulletLayer)
	{
		bool isCollided = false;
		sf::FloatRect bulletRect(
			bullet.getBulletObject().getPosition(),
			{bullet.getBulletObject().m_sprite.getGlobalBounds().height *
				 bullet.getBulletObject().m_scale,
			 bullet.getBulletObject().m_sprite.getGlobalBounds().width *
				 bullet.getBulletObject().m_scale});
		for (auto &object : drawLayer)
		{
			if (object.isCollider() && object.check_collision(bulletRect))
			{
				isCollided = true;
				break;
			}
		}
		if (!isCollided && bullet.isExist)
			bullet.moveBullet(deltatime);
		else
		{
			bullet.isExist = false;
		}
	}

	for (auto &bullet : bulletLayer)
	{
		bool isCollided = false;
		sf::FloatRect bulletRect(
			bullet.getBulletObject().getPosition(),
			{bullet.getBulletObject().m_sprite.getGlobalBounds().height *
				 bullet.getBulletObject().m_scale,
			 bullet.getBulletObject().m_sprite.getGlobalBounds().width *
				 bullet.getBulletObject().m_scale});
		for (auto &object : enemies)
		{
			if (bullet.isExist and (not object.getDead()) and
				object.getEnemyObject().check_collision(bulletRect))
			{
				object.hit(25);
				bullet.isExist = false;

				// check if all enemies killed
				auto alive_number = std::count_if(enemies.cbegin(), enemies.cend(), [](EyeEnemy e)
												  { return not e.getDead(); });
				if (alive_number == 0)
				{
					difficulty *= 2;
					new_wave();
				}
				break;
			}
		}
	}

	sf::Vector2i currentPlayerPos(player.getPlayerPosition());
	currentPlayerPos /= 64;
	auto delta = currentPlayerPos - previousPlayerPosition;
	if (fabs(delta.x) > 1.0f or fabs(delta.y) > 1.0f)
	{
		auto sprites = spriteController.spriteArrays["world"];
		std::cout << "updating world" << std::endl;
		drawLayer.clear();
		previousPlayerPosition = sf::Vector2i(player.getPlayerPosition() / 64.0f);
		draw_world(sprites);
	}
}

void Game::updateAnimations(sf::Time deltatime)
{
	for (auto &object : animatedLayer)
	{
		object.nextState();
	}
	for (auto &object : bulletLayer)
	{
		object.getBulletObject().nextState();
	}
	for (auto &object : enemies)
	{
		object.getEnemyObject().nextState();
	}
	player.get_playerObject().nextState();
}

/**
 * Drawing all layers
 */
void Game::draw(sf::Time deltaTime)
{

	if (paused)
		window.setView(map);
	else
		window.setView(camera);
	window.clear(sf::Color(16, 0, 41));
	// draw_world(sprites);
	for (auto &object : drawLayer)
	{
		window.draw(object);
	}
	for (auto &object : animatedLayer)
	{
		window.draw(object);
	}

	// TEST
	spriteController.load_sprites("crosshair", "../src/Assets/crosshair.png",
								  {8, 8});
	auto sprite = spriteController.spriteArrays["crosshair"][0];
	auto localMousePos = sf::Mouse::getPosition(window);
	auto worldPos = window.mapPixelToCoords(localMousePos);
	GameObject cursor({(float)worldPos.x - 20, (float)worldPos.y - 20}, sprite);
	cursor.setScale(5, 5);

	if (worldPos.x < player.getPlayerPosition().x)
	{
		player.mirrorSprite(false);
	}
	else
	{
		player.mirrorSprite(true);
	}

	window.draw(cursor);
	for (auto &object : enemies)
	{
		window.draw(object);
	}
	window.draw(player);
	for (auto &object : bulletLayer)
	{
		if (object.isExist)
			window.draw(object);
	}
	window.display();
}

void Game::run()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile(
		toml::find<std::string>(settingsManager.SoundSettings, "bg_music"));
	sf::Sound bg_music;
	bg_music.setBuffer(buffer);
	bg_music.setVolume(10);
	bg_music.play();
	sf::Vector2f startPlayerPosition(200, 200);
	window.setMouseCursorVisible(false);
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS);
	sf::Time timePerAnimation = sf::seconds(1.0f / 10);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timeSinceLastAnimation = sf::Time::Zero;

	new_wave();

	auto sprites = spriteController.spriteArrays["world"];
	auto player_sprites = spriteController.spriteArrays["player"];

	// draw_test_room(sprites);

	while (window.isOpen())
	{
		auto deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;
		timeSinceLastAnimation += deltaTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents();
			if (not paused)
			{
				update(timePerFrame);
			}
		}
		while (timeSinceLastAnimation > timePerAnimation)
		{
			timeSinceLastAnimation -= timePerAnimation;
			if (not paused)
			{
				updateAnimations(timePerAnimation);
			}
		}
		draw(deltaTime);
	}
}

/**
 * @brief генерация и отрисовка игрового мира в области вокруг игрока
 *
 * @param sprites спрайты игрового мира
 */
void Game::draw_world(std::vector<sf::Sprite> sprites)
{
	toml::find<float>(settingsManager.WorldGenSettings, "frequency");

	auto size{64};
	float frequency = toml::find<float>(settingsManager.WorldGenSettings, "frequency");
	float amplitude = toml::find<float>(settingsManager.WorldGenSettings, "amplitude");
	sf::Vector2f cord(sf::Mouse::getPosition());
	cord.x /= WINDOW_SIZE_W;
	cord.y /= WINDOW_SIZE_H;
	float lacunarity = toml::find<float>(settingsManager.WorldGenSettings, "lacunarity");
	float persistence = 1 / lacunarity;
	SimplexNoise n(frequency, amplitude, lacunarity, persistence);
	sf::View currentView = window.getView();
	int genWidth{currentView.getSize().x / size + 5};
	int genHeight{currentView.getSize().y / size + 5};
	for (int i = -genWidth; i < genWidth; i++)
	{
		for (int j = -genHeight; j < genHeight; j++)
		{
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
			if (floor_start < normalized && normalized < floor_end)
			{
				rectt.setFillColor(sf::Color(255, 0, 0)); // wall
				tile = {sf::Vector2f(x * size, y * size),
						spriteController.spriteObjects["wall"], true, 6};
			}
			else if (normalized > floor_end)
			{
				rectt.setFillColor(sf::Color(0, 250, 0)); // floor
				tile = {sf::Vector2f(x * size, y * size),
						spriteController.spriteObjects["floor"], false, 6};
			}
			drawLayer.push_back(tile);
		}
	}
}

void Game::draw_test_room(std::vector<sf::Sprite> sprites)
{
	int scale = 8;
	int size_x = 20;
	int size_y = 20;
	int x_offset = 100;
	int y_offset = 100;
	for (int i = 0; i <= size_y * 8 * scale; i += 8 * scale)
	{
		for (int j = 0; j <= size_x * 8 * scale; j += 8 * scale)
		{
			GameObject floor;

			if (i == size_y * 8 * scale || i == 0 || j == 0 ||
				j == size_x * 8 * scale)
				floor = {sf::Vector2f(x_offset + i, y_offset + j),
						 spriteController.spriteObjects["wall"], true, 8};
			else if (j == 8 * scale)
			{
				floor = {sf::Vector2f(x_offset + i, y_offset + j),
						 spriteController.spriteObjects["floor_shadow_top"], false, 8};
			}
			else if (i == 8 * scale)
			{
				floor = {sf::Vector2f(x_offset + i, y_offset + j),
						 spriteController.spriteObjects["floor_shadow_left"], false, 8};
			}
			else if (i == 8 * scale * (size_x - 1))
			{
				floor = {sf::Vector2f(x_offset + i, y_offset + j),
						 spriteController.spriteObjects["floor_shadow_right"], false,
						 8};
			}
			else
			{
				int sprite_id = rand() % 3;
				floor = {sf::Vector2f(x_offset + i, y_offset + j),
						 spriteController.spriteObjects["floor"], false, 8};
			}
			drawLayer.push_back(floor);
		}
	}
}

void Game::new_wave()
{
	enemies.clear();
	player.resetHealth();
	for (int i = 0; i < difficulty; i++)
	{
		EyeEnemy enemy(
			{(float)(rand() % 1300) + 200, (float)(rand() % 1300) + 200},
			spriteController.spriteArrays["enemy_move"],
			spriteController.spriteArrays["enemy_attack"],
			spriteController.spriteArrays["enemy_hit"],
			spriteController.spriteArrays["enemy_death"], 70, 110,
			toml::find<std::string>(settingsManager.SoundSettings, "enemy_hit"), difficulty * 30);

		enemies.push_back(enemy);
	}
}
