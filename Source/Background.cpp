#include "Background.hpp"

Background::Background(sf::RenderWindow& window)
	: window(window)
{
	texture.loadFromFile("assets/background.png");
	texture.setRepeated(true);

	sprite.setTexture(texture);
	sprite.setOrigin((sf::Vector2f) texture.getSize() / 2.0f);
}

void Background::update(const sf::Vector2f& spaceshipPosition)
{
	sprite.setPosition(spaceshipPosition);
	sprite.setTextureRect(sf::IntRect((int) spaceshipPosition.x, (int) spaceshipPosition.y, texture.getSize().x, texture.getSize().y));
}

void Background::render()
{
	window.draw(sprite);
}