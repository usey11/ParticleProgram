#include <SFML/Graphics.hpp>
#include "program.hpp"


int main()
{

	sf::RenderWindow window(sf::VideoMode(1360, 768), "SFML works!",sf::Style::Fullscreen);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	programLoop p1(window);
	p1.loop();

	return 0;
}
