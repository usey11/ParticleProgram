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
	int error = 0;

	Menu menu;
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
	text.setPosition(400, 300);

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

Menu::Menu()
{
	menuImage.loadFromFile("mainMenu.png");
	menu.setTexture(menuImage);
}

void Menu::draw(sf::RenderWindow &w)
{
	w.draw(menu);
}