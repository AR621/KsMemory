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
				if (gamestate.state() == 0)
				{
					sf::Vector2i Position = sf::Mouse::getPosition(window);
					int ClickedCardNum = gameboard.ClickCheck(gamestate.GetNumOfCards(), Position.x, Position.y);	
					if (ClickedCardNum >= 0 && ClickedCardNum < 30)
						gameboard.reveal(ClickedCardNum);
					gamestate.CheckGameState(gameboard);
					gamestate.SaveRevealedCardId(gameboard.ReturnBoard().at(ClickedCardNum).GetId());
				}
			}
			if (gamestate.state() == 1)
				std::cout << "  :" << gamestate.CheckCards() << ":  ";
		}
		//Display
		window.clear();
		for (int i = 0; i < gamestate.GetNumOfCards(); i++)
			window.draw(gameboard.ReturnBoard().at(i));
		window.display();
	}
	return 0;
}
