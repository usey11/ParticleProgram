#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class menuItem;
class Menu;

class programLoop
{
public:
	programLoop(sf::RenderWindow &w);
	void loop();

private:

	sf::RenderWindow *window;
};

class Menu
{
public:
	Menu(sf::RenderWindow &w);
	void draw(sf::RenderWindow &w);
	int checkEvents(sf::Event,float,float);

	int leftDifference;
	int topDifference;

	void resetSignals();
	//bool unpause;


private:

	sf::Texture menuImage;
	sf::Sprite menu;

};
