#include <iostream>
#include "gameboard.h"
#include "gamestate.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main()
{
	bool menuScreen = true;
	//Handling window
	float dimensions[4] = { 1024.0, 600.0, 1480.0, dimensions[1] * dimensions[2] / dimensions[0] };//dimensions [0] and [1] are window x and y sizes. dimensions [2] and [3] are view x and y sizes;
	sf::RenderWindow window(sf::VideoMode(dimensions[0], dimensions[1]), "KsMemory");
	sf::View view(sf::FloatRect(0, 0, dimensions[2], dimensions[3]));
	window.setView(view);
	window.setFramerateLimit(60);

	//Initialising menu
	menu menu;
	//Initialising game
	gamestate gamestate;
	gameboard gameboard;

	while (window.isOpen())
	{
		//Updating window dimensions in case of resize
		dimensions[0] = window.getSize().x;
		dimensions[1] = window.getSize().y;
		sf::Event event;
		if (menu.IsInMenu())
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					sf::Vector2i Position = sf::Mouse::getPosition(window);
					int playerChoice;
					switch (menu.MenuClickCheck(Position.x, Position.y, dimensions))
					{
					case 1:
						menu.StartGame();
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
			}
		else
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				//Clicks
				case sf::Event::MouseButtonPressed:
					{	
						sf::Vector2i Position = sf::Mouse::getPosition(window);
						int ClickedCardNum = gameboard.ClickCheck(gamestate.GetNumOfCards() , Position.x, Position.y, dimensions);	
						if (ClickedCardNum >= 0 && ClickedCardNum < 30)
						{
							gameboard.reveal(ClickedCardNum);
							gamestate.SaveRevealedCard(gameboard.ReturnBoard().at(ClickedCardNum).GetId());
							gameboard.SaveRevealedCard(ClickedCardNum);
						}
					}
					if (gamestate.state() == 2)
					{
						sf::Vector2i Position = sf::Mouse::getPosition(window);
						if (menu.EndClickCheck(Position.x, Position.y, dimensions))
						{
							menu.ToMenu();
							gamestate.ResetGame();
							break;
						}
					}
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{
						menu.drawPopup(window);
						window.display();
						int popupClicked = 0;
						while (popupClicked != 1)
						{
							sf::Vector2i Position;
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								Position = sf::Mouse::getPosition(window);
							popupClicked = menu.PopupClickCheck(Position.x, Position.y, dimensions);
							if (popupClicked == 2)
							{
								menu.ToMenu();
								gamestate.ResetGame();
								break;
							}
							if (popupClicked == 3)
								return 0;
						}
					}
				}
			}
		//Display
		if (menu.IsInMenu())
		{
			//Menu display
			window.clear();
			window.draw(menu.Title());
			window.draw(menu.Welcome());
			window.draw(menu.Play());
			window.draw(menu.Exit());
			window.display();
			//Game reset
			if (gamestate.ToReset())
			{
				gameboard.Generate_Board(gamestate);
				gameboard.LoadTextures(gamestate);
				gamestate.GamestateReset();
			}
		}
		else 
		{
			if (gamestate.state() == !2)
			{
				//Game display
				window.clear();
				for (int i = 0; i < gamestate.GetNumOfCards(); i++)
					gameboard.ReturnBoard().at(i).drawCard(window);
				window.display();
				//StateCheck
				gamestate.CheckGameState(gameboard);
				if (gamestate.state() == 1)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(625));
					gameboard.resolve(gamestate.CheckCards());
				}
			}
			else
			{
				//End screen
				window.draw(menu.EndMsg());
				menu.setScore(gamestate.getScore());
				window.draw(menu.Score());
				window.draw(menu.Return2Menu());
				window.display();
			}
		}
		
	}
	return 0;
}
