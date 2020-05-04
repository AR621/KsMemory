#include <iostream>
#include "gameboard.h"
#include "gamestate.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1480,800), "KsMemory ALPHA");
	window.setFramerateLimit(30);
	gamestate gamestate;
	gameboard gameboard;
	gameboard.Generate_Board(gamestate);
	gameboard.LoadTextures(gamestate);
	gameboard.Debug(gamestate.GetNumOfCards());
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (gamestate.state() == 0)
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				//Clicks
				case sf::Event::MouseButtonPressed:
					sf::Vector2i Position = sf::Mouse::getPosition(window);
					int ClickedCardNum = gameboard.ClickCheck(gamestate.GetNumOfCards(), Position.x, Position.y);	
					if (ClickedCardNum >= 0 && ClickedCardNum < 30)
					{
						gameboard.reveal(ClickedCardNum);
						gamestate.CheckGameState(gameboard);
						gamestate.SaveRevealedCard(gameboard.ReturnBoard().at(ClickedCardNum).GetId());
						gameboard.SaveRevealedCard(ClickedCardNum);
					}
			}
		}
		//Display
		window.clear();
		for (int i = 0; i < gamestate.GetNumOfCards(); i++)
			gameboard.ReturnBoard().at(i).drawCard(window);
		window.display();
		//StateCheck
		if (gamestate.state() == 1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(625));
			gameboard.resolve(gamestate.CheckCards());
		}
	}
	return 0;
}
