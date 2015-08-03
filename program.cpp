#include "program.hpp"
#include "particle.hpp"
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

	particle_system system1(50000, window->getSize());

	sf::Clock c1;

	bool paused = true;
	bool toPoint = false;

	Menu menu(*window);
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



	system1.randomPos();
	system1.randomVs();

	
	c1.restart();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)				//Close
				window->close();								//Close

			if (event.type == sf::Event::KeyPressed)			//Key Shortcuts
			{
				if (event.key.code == sf::Keyboard::P)			//P for Pause
				{
					paused = !paused;
					c1.restart();
				}												//P for Pause
			}													//Key Shortcuts

			//Menu Buisness
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left && toPoint == true){
					system1.towardsPoint(sf::Mouse::getPosition(*window));
					toPoint = false;
				}
				else if (event.mouseButton.button == sf::Mouse::Right && toPoint == true){
					system1.towardsPoint(sf::Mouse::getPosition(*window));
				}
			}

			int a = 0;
			if (paused == true)
				a = menu.checkEvents(event, sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

			if (a == 1){
				paused = false;
				c1.restart();
				menu.resetSignals();
			}

			if (a == 2){

				system1.randomPos();
				system1.randomVs();

				paused = false;
				c1.restart();
				menu.resetSignals();
			}

			if (a == 3){
				toPoint = true;
				paused = false;
				c1.restart();
				menu.resetSignals();
			}
		}
		//Menu Buisness

		if (c1.getElapsedTime().asSeconds() > 0.01 && paused == false)
		{
			system1.move(c1.restart());
		}


		window->clear();
		//menu.draw(*window);
		if (paused == false)
			system1.draw(*window,window->getDefaultView());
		else{
			system1.draw(*window, window->getDefaultView());
			menu.draw(*window);
		}
		window->display();
	}
}

Menu::Menu(sf::RenderWindow &w)
{
	menuImage.loadFromFile("mainMenu.png");
	menu.setTexture(menuImage);

	menu.setOrigin(menu.getLocalBounds().width /2, menu.getLocalBounds().height/2);
	menu.setPosition(w.getSize().x / 2, w.getSize().y / 2);

}

void Menu::draw(sf::RenderWindow &w)
{
	w.draw(menu);
}

int Menu::checkEvents(sf::Event e,float x , float y)
{
	if (e.type == sf::Event::MouseButtonPressed)
	{
		//std::cout << "Clicked";
		if (e.mouseButton.button == sf::Mouse::Left)
		{
			//float x = sf::Mouse::getPosition().x;
			//float y = sf::Mouse::getPosition().y;
			if (x > 300 && x < 500 && y >164 && y < 237){
				std::cout << "UNPAUSEEE";
				//unpause = true;
				return 1;
			}

			if (x > 300 && x < 500 && y >237 && y < 292){
				std::cout << "RESET";
				//unpause = true;
				return 2;
			}

			if (x > 300 && x < 500 && y >292 && y < 365){
				std::cout << "TO POINT";
				//unpause = true;
				return 3;
			}
		}

	}

	return 0;
}

void Menu::resetSignals()
{
	//pause = false;
}