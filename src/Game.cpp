#include "Game.hpp"

Game::Game(unsigned int h, unsigned int w)
	: WINDOW_SIZE_H(h),
	  WINDOW_SIZE_W(w),
	  window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_W, WINDOW_SIZE_H),
							  "Smart Slimes",
							  sf::Style::Titlebar | sf::Style::Close)),
	  FPS{70},
	  paused{false}
{
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
			// printf("pizda\n");
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

			default:
				break;
			}
		}
		default:
			break;
		}
	}
}

void Game::update(sf::Time deltatime)
{
	// call update method for all game objects
}

void Game::draw()
{
	// clear and fill the window with color
	window.clear(sf::Color(100, 100, 100));
	// call display method for all game objects
	window.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents();
			if (not paused)
			{
				update(timePerFrame);
			}
		}
		draw();
	}
}
