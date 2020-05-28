#include <iostream>
#include "gameboard.h"
#include "gamestate.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main()
{
	//Handling window
	float dimensions[4] = { 1024.0, 600.0, 1480.0, dimensions[1] * dimensions[2] / dimensions[0] };
	sf::RenderWindow window(sf::VideoMode(dimensions[0], dimensions[1]), "KsMemory ALPHA");//, sf::Style::Fullscreen);
	sf::View view(sf::FloatRect(0, 0, dimensions[2], dimensions[3]));
	window.setView(view);
	window.setFramerateLimit(60);

	menu menu;

	//Initialising game
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
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				//Clicks
				case sf::Event::MouseButtonPressed:
					if (gamestate.state() == 0);
					{
						sf::Vector2i Position = sf::Mouse::getPosition(window);
						dimensions[0]= window.getSize().x;
						dimensions[1]= window.getSize().y;
						int ClickedCardNum = gameboard.ClickCheck(gamestate.GetNumOfCards() , Position.x, Position.y, dimensions);	
						if (ClickedCardNum >= 0 && ClickedCardNum < 30)
						{
							gameboard.reveal(ClickedCardNum);
							gamestate.CheckGameState(gameboard);
							gamestate.SaveRevealedCard(gameboard.ReturnBoard().at(ClickedCardNum).GetId());
							gameboard.SaveRevealedCard(ClickedCardNum);
						}
					}
			}
		}
		//Display
		/*window.clear();
		window.draw(menu.Title());
		window.draw(menu.Welcome());
		window.draw(menu.Play());
		window.draw(menu.Exit());
		window.display();
*/
		window.clear();
		for (int i = 0; i < gamestate.GetNumOfCards(); i++)
			gameboard.ReturnBoard().at(i).drawCard(window);
		window.display();
		//StateCheck
		if (gamestate.state() == 1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(425));
			gameboard.resolve(gamestate.CheckCards());
		}
	}
	return 0;
}
