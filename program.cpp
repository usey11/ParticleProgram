#include "program.hpp"

programLoop::programLoop(sf::RenderWindow &w)
{
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	window = &w;
}

void programLoop::loop()
{
  int error  = 0;

  Menu menu(1,*window);
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text text("Jacob", font);
	text.setCharacterSize(60);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);

	sf::FloatRect tRect = text.getLocalBounds();
	float h = tRect.height;
	float w = tRect.width;

	text.setOrigin(w / 2, h / 2);
	text.setPosition(400,300);

  while (window->isOpen())
  {
	  sf::Event event;
	  while (window->pollEvent(event))
	  {
		  if (event.type == sf::Event::Closed)
			  window->close();
	  }




	  window->clear();
	  menu.draw(*window);
	  window->draw(text);
	  window->display();
  }
}

Menu::Menu(int a, sf::RenderWindow &w)
	:outBox(sf::Vector2f(200, 400)), paused(sf::Vector2f(200,80))
{
	outBox.setOrigin(100,200);
	outBox.setPosition(400,300);
	outBox.setFillColor(sf::Color::Black);
	outBox.setOutlineThickness(2);
	outBox.setOutlineColor(sf::Color::Red);

	paused.setOrigin(100, 0);
	paused.setPosition(400, 100);
	paused.setOutlineColor(sf::Color::Red);
	paused.setFillColor(sf::Color::Black);
	paused.setOutlineThickness(2);

	std::cout <<a;
	window = &w;
}

void Menu::draw(sf::RenderWindow &w)
{
	w.draw(outBox);
	w.draw(paused);
}

sf::RectangleShape Menu::getOutBox()
{
	return outBox;
}

menuItem::menuItem(std::string text, Menu &parentMenu,int nunmberOfItems, int itemNumber)
{
	windowHeight = parentMenu.window->getSize().y;
	windowLength = parentMenu.window->getSize().x;

	menuHeight = parentMenu.getOutBox().getSize().y;
	menuWidth = parentMenu.getOutBox().getSize().x;

	ItemSize.X = menuWidth;
	ItemSize.Y = menuHeight/nunmberOfItems;

	box = sf::RectangleShape(ItemSize.X , ItemSize.Y);
	box.setPosition(windowLength/2  - ItemSize.X /2 , (windowHeight - menuHeight)/2);
	box.setOutlineThickness(2);
	box.setOutlineColor(sf::Color::Red);
	box.setFillColor(sf::Color::White);



}
