#include <SFML/Graphics.hpp>
#include "program.hpp"


int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!"); //Makes window to draw to
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	programLoop p1(window); //Loop for program
	p1.loop(); //Starts loop

	return 0;
}
