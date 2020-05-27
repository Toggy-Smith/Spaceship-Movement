#pragma once

#include "SFML/Graphics.hpp"

#include "svl.hpp"

#include <cmath>

class Spaceship
{
	private:
		sf::RenderWindow& window;

		sf::Texture       texture;
		sf::Sprite        sprite;

		svl::Vector2f     velocityVector;

		const float       movementSpeed      = 5.0f;
		const float       movementFriction   = 2.5f;
		const float       maxMovementSpeed   = 1000.0f;

		const float       rotationSpeed      = 1.5f;

	public:
		                    Spaceship   (sf::RenderWindow&);

		void                handleEvent (const sf::Event&);
		void                update      (const float);
		void                render      ();

		const sf::Vector2f& getPosition() const { return sprite.getPosition(); }
};