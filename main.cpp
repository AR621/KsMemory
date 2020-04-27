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
	sf::RenderWindow window(sf::VideoMode(1400,800), "KsMemory ALPHA");
	sf::RectangleShape card(sf::Vector2f(120.0f,180.0f));
	gamestate gamestate;
	gameboard gameboard;
	gameboard.Generate_Board(gamestate);
	gameboard.Display_Board(gamestate.GetNumOfCards());
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
			}
		}
		window.draw(card);
		window.display();
	}
	return 0;
}
