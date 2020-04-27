#include <iostream>
#include "gameboard.h"
#include "gamestate.h"
#include "card.h"
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1480,800), "KsMemory ALPHA");
	window.setFramerateLimit(30);
	gamestate gamestate;
	gameboard gameboard;
	gameboard.Generate_Board(gamestate);
	gameboard.Debug(gamestate.GetNumOfCards());
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			//Clicks
			case sf::Event::MouseButtonPressed:
				sf::Vector2i Position = sf::Mouse::getPosition(window);
				//std::cout << Position.x << " : " << Position.y;
				int ClickedId = gameboard.ClickCheck(gamestate.GetNumOfCards(), Position.x, Position.y);
				gameboard.ReturnBoard().at(ClickedId).reveal();
				break;
			}
		}
		//Display
		window.clear();
		for (int i = 0; i < gamestate.GetNumOfCards(); i++)
			window.draw(gameboard.ReturnBoard().at(i));
		window.display();
	}
	return 0;
}
