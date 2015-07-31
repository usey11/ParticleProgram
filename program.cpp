#include "program.hpp"
struct sizes
{
	float windowHeight;
	float windowLength;
	float menuHeight;
	float menuLength;
};
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
	sizes s1;
	s1.windowHeight = window->getSize().y;
	s1.windowLength = window->getSize().x;

	s1.menuHeight = outBox.getSize().y;
	s1.menuLength = outBox.getSize().x;

	item = new menuItem("kkk", this, 5, 1);
}

void Menu::draw(sf::RenderWindow &w)
{
	w.draw(outBox);
	w.draw(paused);
	item->draw(w);
}

sf::RectangleShape Menu::getOutBox()
{
	return outBox;
}


menuItem::menuItem(std::string text, Menu *parentMenu, int nunmberOfItems, int itemNumber)
{
	windowHeight = parentMenu->window->getSize().y;
	windowLength = parentMenu->window->getSize().x;

	menuHeight = parentMenu->getOutBox().getSize().y;
	menuWidth = parentMenu->getOutBox().getSize().x;

	ItemSize.x = menuWidth;
	ItemSize.y = menuHeight / nunmberOfItems;

	box = sf::RectangleShape(sf::Vector2f(ItemSize.x, ItemSize.y));
	box.setPosition(windowLength / 2 - ItemSize.x / 2, (windowHeight - menuHeight) / 2);
	box.setOutlineThickness(2);
	box.setOutlineColor(sf::Color::Red);
	box.setFillColor(sf::Color::White);
}

void menuItem::draw(sf::RenderWindow &w)
{
	w.draw(box);
}