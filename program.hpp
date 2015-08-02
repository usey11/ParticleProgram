#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

class menuItem;
class Menu;

class programLoop
{
public:
	programLoop(sf::RenderWindow &w);
	void loop();
	sf::Text t;
private:

	sf::RenderWindow *window;
};

class Menu
{
public:
	Menu();
	void draw(sf::RenderWindow &w);

private:
	sf::Texture menuImage;
	sf::Sprite menu;

};