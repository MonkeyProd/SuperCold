#include "EyeEnemy.hpp"

EyeEnemy::EyeEnemy(sf::Vector2f startPosition,
                   std::vector<sf::Sprite> moveSprites,
                   std::vector<sf::Sprite> attackSprites,
                   std::vector<sf::Sprite> takeDamageSprites,
                   std::vector<sf::Sprite> deathSprites, float speed,
                   float attack_distance, std::string enemyHitSound, int health)
    : m_moveSprites(moveSprites), m_attackSprites(attackSprites),
      m_takeDamageSprites(takeDamageSprites), m_deathSprites(deathSprites),
      m_speed(speed),
      m_EyeEnemyObject(startPosition, moveSprites, true, 2.8, {50, 50}),
      m_attack_distance(attack_distance), m_health(health),
      initial_health(health) {
	attackTime = sf::Time();
	setPosition(startPosition);
	m_sbuffer.loadFromFile(enemyHitSound);
	hitSound.setBuffer(m_sbuffer);
	hitSound.setPitch(2);
	hitSound.setVolume(40);
	m_canAttack = true;
}

GameObject &EyeEnemy::getEnemyObject() { return m_EyeEnemyObject; }

bool EyeEnemy::getDead() const { return isDead; }

void EyeEnemy::hit(int damage) {
	if (isHitted && isDead) {
		return;
	}
	hitSound.setBuffer(m_sbuffer);
	hitSound.play();
	isHitted = true;
	m_health -= damage;
	if (m_health <= 0) {
		m_EyeEnemyObject.resetAnimation();
		m_EyeEnemyObject.stopAtEnd = true;
		m_EyeEnemyObject.m_sprites_array = m_deathSprites;
		isDead = true;
	} else {
		m_EyeEnemyObject.m_sprites_array = m_takeDamageSprites;
	}
}

sf::FloatRect EyeEnemy::getNextPosition(sf::Time deltaTime,
                                        sf::Vector2f positionTowards) const {
	sf::Vector2f velocity = calculateTowardsVector(positionTowards);
	sf::FloatRect nextPosition = m_EyeEnemyObject.getGameObjectRect();
	nextPosition.top += velocity.y * deltaTime.asSeconds();
	nextPosition.left += velocity.x * deltaTime.asSeconds();
	return nextPosition;
}

sf::Vector2f EyeEnemy::calculateTowardsVector(sf::Vector2f position) const {
	sf::Vector2f moveTo = (position - m_EyeEnemyObject.getPosition());
	moveTo /= std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y);
	moveTo.x *= m_speed;
	moveTo.y *= m_speed;
	return moveTo;
}

void EyeEnemy::moveTowards(sf::Vector2f position, sf::Time deltaTime) {
	if (!isHitted && !isDead) {
		sf::Vector2f moveTo = (position - m_EyeEnemyObject.getPosition());
		if (std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y) <=
		    m_attack_distance) {
			m_EyeEnemyObject.m_sprites_array = m_attackSprites;
		} else {
			m_EyeEnemyObject.m_sprites_array = m_moveSprites;
			moveTo /= std::sqrt(moveTo.x * moveTo.x + moveTo.y * moveTo.y);
			move(moveTo * m_speed * deltaTime.asSeconds());
			m_EyeEnemyObject.move(moveTo * m_speed * deltaTime.asSeconds());
		}
		if (attackTime.asSeconds() > 2) {
			attackTime = sf::Time();
			m_canAttack = true;
		}
	} else {
		if (m_EyeEnemyObject.isLastAnimationState())
			isHitted = false;
	}
	attackTime += deltaTime;
}

void EyeEnemy::draw(sf::RenderTarget &surface, sf::RenderStates states) const {
	if (not isDead) {
		sf::Vector2f HealthBarSize(80, 15);
		sf::RectangleShape maxhealth(HealthBarSize);
		maxhealth.setFillColor(sf::Color(200, 200, 200));
		maxhealth.setPosition(getPosition() + sf::Vector2f(10, 0));
		surface.draw(maxhealth);
		sf::RectangleShape currenthealth(sf::Vector2f(
		    HealthBarSize.x * m_health / initial_health, HealthBarSize.y));
		currenthealth.setFillColor(sf::Color(0, 255, 0));
		currenthealth.setPosition(getPosition() + sf::Vector2f(10, 0));
		surface.draw(currenthealth);
	}
	surface.draw(m_EyeEnemyObject);
}

bool EyeEnemy::canAttack() const { return m_canAttack; }

void EyeEnemy::attacked() { m_canAttack = false; }