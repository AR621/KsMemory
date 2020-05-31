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
	sf::RenderWindow window(sf::VideoMode(dimensions[0], dimensions[1]), "KsMemory ALPHA");//, sf::Style::Fullscreen);
	sf::View view(sf::FloatRect(0, 0, dimensions[2], dimensions[3]));
	window.setView(view);
	window.setFramerateLimit(60);

	//Updating window dimensions in case of resize
	dimensions[0]= window.getSize().x;
	dimensions[1]= window.getSize().y;
	//Initialising menu
	menu menu;
	//Initialising game
	gamestate gamestate;
	gameboard gameboard;

	while (window.isOpen())
	{
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
					dimensions[0]= window.getSize().x;
					dimensions[1]= window.getSize().y;
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
					if (gamestate.state() == 0);
					{
						sf::Vector2i Position;
						Position.x = 0;
						Position.y = 0;
					 	Position = sf::Mouse::getPosition(window);
						int ClickedCardNum = gameboard.ClickCheck(gamestate.GetNumOfCards() , Position.x, Position.y, dimensions);	
						if (ClickedCardNum >= 0 && ClickedCardNum < 30)
						{
							gameboard.reveal(ClickedCardNum);
							gamestate.SaveRevealedCard(gameboard.ReturnBoard().at(ClickedCardNum).GetId());
							gameboard.SaveRevealedCard(ClickedCardNum);
							gamestate.CheckGameState(gameboard);
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
			//Menu
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
				gameboard.Debug(gamestate.GetNumOfCards());
			}
		}
		else
		{
			//Game
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
	}
	return 0;
}
