#include "Game.hpp"


void test_application()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Test application");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}


int main()
{
	//just to check if sfml works
	// test_application();

	Game g;
	g.run();
	return 0;
}
