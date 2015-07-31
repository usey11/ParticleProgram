#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

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
  Menu(int,sf::RenderWindow &w);
  void draw(sf::RenderWindow &w);
  sf::RenderWindow *window;
  sf::RectangleShape getOutBox();
private:
  sf::RectangleShape outBox;
  sf::RectangleShape paused;


  //Paused
  //Resume
  //Remake
  //Audio
  //Gravity
};

class menuItem :public sf::Drawable
{
public:
	menuItem(std::string, Menu&,int,int);
	//active


private:
	sf::RectangleShape box;

	float windowHeight;
	float windowLength;

	float menuHeight;
	float menuWidth;

  sf::Vector2f ItemSize;
};
