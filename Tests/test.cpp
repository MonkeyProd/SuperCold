#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define TESTING 1
#include "../Game/Game.hpp"

TEST_CASE("Player hit") {
	Game g;
	REQUIRE(g.player.getHealth() == 100);
	g.player.getHit(50);
	CHECK(g.player.getHealth() == 50);
}

TEST_CASE("Player move") {
	Game g;
	REQUIRE_EQ(g.player.getPlayerVelocity(),
	        sf::Vector2f(0, 0)); //сравнение float с помощью ==
	g.player.changeXDirection(Player::HorizontalDirection::Right);
	CHECK_EQ(g.player.getPlayerVelocity(), sf::Vector2f(g.player.m_speed, 0));
}
