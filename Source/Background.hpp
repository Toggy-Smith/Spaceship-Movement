#include "SFML/Graphics.hpp"

class Background
{
	private:
		sf::RenderWindow& window;

		sf::Texture       texture;
		sf::Sprite        sprite;

	public:
		Background(sf::RenderWindow&);

		void update(const sf::Vector2f&);
		void render();
};