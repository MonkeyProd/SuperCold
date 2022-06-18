#include "Player.hpp"

Player::Player(sf::Vector2f startPosition, sf::Vector2f velocity,
               spritesMap playerSprites, std::string footsteps_path,
               float speed, int p_health)
    : m_velocity(velocity), m_position(startPosition),
      m_playerSprites(playerSprites), m_speed(speed), isLookRight(true),
      health(p_health), initial_health(p_health), getting_hit(false) {
	GameObject playerObject({startPosition.x - 8, startPosition.y - 8},
	                        m_playerSprites["player_forward"], false, 4,
	                        {60, 60});
	m_playerObject = playerObject;
	m_current_state = m_playerSprites["player_forward"];
	m_sbuffer.loadFromFile(footsteps_path);
	m_footstepsSound.setBuffer(m_sbuffer);
	m_footstepsSound.setVolume(80);
	m_footstepsSound.setPitch(1);
	m_footstepsSound.setLoop(true);
}

GameObject &Player::get_playerObject() { return m_playerObject; }

void Player::changeXDirection(HorizontalDirection direction) {
	m_velocity.x = direction == HorizontalDirection::Left ? -m_speed : m_speed;
	isMoveHorizontal = true;
}
void Player::changeYDirection(VerticalDirection direction) {
	m_velocity.y = direction == VerticalDirection::Top ? -m_speed : m_speed;
	isMoveVertical = true;
}

void Player::resetHorizontalVelocity() {
	m_velocity.x = 0;
	isMoveHorizontal = false;
}
void Player::resetVerticalVelocity() {
	m_velocity.y = 0;
	isMoveVertical = false;
}

void Player::setSpeed(float speed) { m_speed = speed; }

bool Player::isDead() const { return health <= 0; }

void Player::resetHealth() { health = initial_health; }

void Player::movePlayer(sf::Time deltaTime) {
	if ((isMoveHorizontal || isMoveVertical) && !isStepping) {
		m_footstepsSound.setBuffer(m_sbuffer);
		m_footstepsSound.play();
		isStepping = true;
	} else {
		if (isStepping && !(isMoveHorizontal || isMoveVertical)) {
			m_footstepsSound.pause();
			isStepping = false;
		}
	}
	if (m_velocity.y > 0) {
		m_playerObject.m_sprites_array = m_playerSprites["player_run_forward"];
		m_current_state = m_playerSprites["player_forward"];
	} else if (m_velocity.y < 0) {
		m_playerObject.m_sprites_array = m_playerSprites["player_run_back"];
		m_current_state = m_playerSprites["player_back"];
	} else if (m_velocity.x < 0) {
		m_playerObject.m_sprites_array = m_playerSprites["player_run_left"];
		m_current_state = m_playerSprites["player_left"];
	} else if (m_velocity.x > 0) {
		m_playerObject.m_sprites_array = m_playerSprites["player_run_right"];
		m_current_state = m_playerSprites["player_right"];
	}
	if (m_velocity.x == 0 && m_velocity.y == 0) {
		m_playerObject.m_sprites_array = m_current_state;
	}
	move(m_velocity * deltaTime.asSeconds());
	m_position = getPosition();
	m_playerObject.move(
	    m_velocity *
	    deltaTime.asSeconds()); //Здесь надо подумать  как одним мувом обойтись
}

sf::Vector2f Player::getPlayerPosition() const { return m_position; }

sf::Vector2f Player::getPlayerVelocity() const { return m_velocity; }

sf::FloatRect Player::getNextPosition(sf::Time deltaTime) const {
	sf::FloatRect nextPosition = m_playerObject.getGameObjectRect();
	nextPosition.top += m_velocity.y * deltaTime.asSeconds();
	nextPosition.left += m_velocity.x * deltaTime.asSeconds();
	return nextPosition;
}

void Player::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
	sf::CircleShape shadow(20);
	shadow.setPosition({m_playerObject.getPosition().x + 10,
	                    m_playerObject.getPosition().y + 45});
	shadow.setScale(1.3, 1);
	shadow.setFillColor(sf::Color(50, 50, 50, 100));
	surface.draw(shadow);
	if (not isDead()) {
		sf::Vector2f offset(0, 65);
		sf::Vector2f HealthBarSize(65, 15);
		sf::RectangleShape maxhealth(HealthBarSize);
		maxhealth.setFillColor(sf::Color(200, 200, 200));
		maxhealth.setPosition(getPosition() + offset);
		surface.draw(maxhealth);
		sf::RectangleShape currenthealth(sf::Vector2f(
		    HealthBarSize.x * health / initial_health, HealthBarSize.y));
		currenthealth.setFillColor(sf::Color(0, 255, 0));
		currenthealth.setPosition(getPosition() + offset);
		surface.draw(currenthealth);
	}

	surface.draw(m_playerObject);
}

void Player::getHit(int hp) {
	health -= hp;
	getting_hit = true;
}

void Player::nextState() {
	m_playerObject.nextState();
	if (getting_hit) {
		getting_hit = false;
		m_playerObject.m_sprite.setColor(sf::Color::Red);
	}
}
