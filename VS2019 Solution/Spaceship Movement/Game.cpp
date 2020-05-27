#include "Game.hpp"

Game::Game(sf::RenderWindow& window)
	: window(window), background(window), spaceship(window)
{
	///
}

void Game::handleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		spaceship.handleEvent(event);

		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::Resized:
				sf::View view = window.getView();

				view.setSize((sf::Vector2f) window.getSize());

				window.setView(view);
		}
	}
}

void Game::update()
{
	static sf::Clock updateClock;

	const float elapsedTime = updateClock.getElapsedTime().asSeconds();

	spaceship.update(elapsedTime);

	background.update(spaceship.getPosition());

	updateClock.restart();
}

void Game::render()
{
	window.clear();

	background.render();

	spaceship.render();

	window.display();
}