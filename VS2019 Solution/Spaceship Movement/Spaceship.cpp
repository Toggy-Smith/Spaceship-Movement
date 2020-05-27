#include "Spaceship.hpp"

Spaceship::Spaceship(sf::RenderWindow& window)
	: window(window)
{
	texture.loadFromFile("assets/spaceship.png");

	sprite.setTexture(texture);
	sprite.setOrigin((sf::Vector2f) texture.getSize() / 2.0f);
}

void Spaceship::handleEvent(const sf::Event& event)
{
	///
}

void Spaceship::update(const float elapsedTime)
{
	// Handle keyboard input
	const float PI = 3.14159f;

	const float angleAsRadians = (sprite.getRotation() + 90.0f) * PI / 180.0f;

	svl::Vector2f directionVector{std::cos(angleAsRadians), std::sin(angleAsRadians)};

	float movementAmount = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movementAmount -= movementSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movementAmount += movementSpeed;

	directionVector *= movementAmount;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.rotate(-rotationSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.rotate(rotationSpeed);

	velocityVector += directionVector;

	// Apply movement friction
	float newVelocityVectorMagnitude = velocityVector.getMagnitude() - movementFriction;

	if (newVelocityVectorMagnitude < 0)
		newVelocityVectorMagnitude = 0;

	velocityVector.setMagnitude(newVelocityVectorMagnitude);

	// Check to see if maximum movement speed has been exceeded
	if (velocityVector.getMagnitude() > maxMovementSpeed)
		velocityVector.setMagnitude(maxMovementSpeed);

	// Move spaceship in accordance with velocity vector
	svl::Vector2f timeAdjustedVelocityVector = velocityVector * elapsedTime;

	sprite.move(timeAdjustedVelocityVector.x, timeAdjustedVelocityVector.y);

	// Center view on spaceship
	sf::View view = window.getView();

	view.setCenter(sprite.getPosition());

	window.setView(view);
}

void Spaceship::render()
{
	window.draw(sprite);
}