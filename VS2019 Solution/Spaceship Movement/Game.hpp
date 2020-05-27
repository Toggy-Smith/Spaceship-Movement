#pragma once

#include "SFML/Graphics.hpp"

#include "Background.hpp"
#include "Spaceship.hpp"

class Game
{
	private:
		sf::RenderWindow& window;

		Background        background;
		Spaceship         spaceship;

	public:
		     Game         (sf::RenderWindow&);

		void handleEvents ();
		void update       ();
		void render       ();
};