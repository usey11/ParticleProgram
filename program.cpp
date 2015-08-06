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
	window = &w;
}

void programLoop::loop()
{
	int error = 0;

	particle_system system1(10000, window->getSize());

	sf::Clock c1;

	bool paused = true;
	bool toPoint = false;

	Menu menu(*window);

	system1.randomPos();
	system1.randomVs();
	system1.setColourScheme(1);


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
					toPoint = false;
				}												//P for Pause

				if (event.key.code == sf::Keyboard::R)			//P for Pause
				{
					c1.restart();
					toPoint = false;

					system1.randomPos();
					system1.randomVs();
				}

				if (event.key.code == sf::Keyboard::Escape)			//Close when esc pressed
				{
					window->close();

				}
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

	leftDifference = (w.getSize().x / 2) - 100;
	topDifference = (w.getSize().y / 2) - 200;

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
			if (x > leftDifference && x < leftDifference + 200 && y >topDifference + 64 && y < topDifference +  137){
				std::cout << "UNPAUSEEE";
				//unpause = true;
				return 1;
			}

			if (x > leftDifference && x < leftDifference + 200 && y > topDifference + 137 && y < topDifference + 192){
				std::cout << "RESET";
				//unpause = true;
				return 2;
			}

			if (x > leftDifference && x < leftDifference + 200 && y > topDifference + 192 && y <topDifference +  265){
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
