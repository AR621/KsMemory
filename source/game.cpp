#include "gameboard.h"
#include "gamestate.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "game.h"

game::game()
{
	Menu;
	State;
	Board;
}

game::~game(){}

void game::UpdateWinSize(sf::RenderWindow& window)
{
	dimensions[0] = window.getSize().x;
	dimensions[1] = window.getSize().y;
}	

void game::HandleMouseClicks(sf::RenderWindow& window, sf::Event event)
{
	if (Menu.IsInMenu())
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
				switch (Menu.MenuClickCheck(Position.x, Position.y, dimensions))
				{
				case 1:
					Menu.StartGame();
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
					int ClickedCardNum = Board.ClickCheck(State.GetNumOfCards() , Position.x, Position.y, dimensions);	
					if (ClickedCardNum >= 0 && ClickedCardNum < 30)
					{
						Board.reveal(ClickedCardNum);
						State.SaveRevealedCard(Board.ReturnBoard().at(ClickedCardNum).GetId());
						Board.SaveRevealedCard(ClickedCardNum);
					}
				}
				if (State.state() == 2)
				{
					sf::Vector2i Position = sf::Mouse::getPosition(window);
					if (Menu.EndClickCheck(Position.x, Position.y, dimensions))
					{
						Menu.ToMenu();
						State.ResetGame();
						break;
					}
				}
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					Menu.drawPopup(window);
					window.display();
					int popupClicked = 0;
					while (popupClicked != 1)
					{
						sf::Vector2i Position;
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							Position = sf::Mouse::getPosition(window);
						popupClicked = Menu.PopupClickCheck(Position.x, Position.y, dimensions);
						if (popupClicked == 2)
						{
							Menu.ToMenu();
							State.ResetGame();
							break;
						}
						if (popupClicked == 3)
							;
					}
				}
			}
		}
}

void game::Display(sf::RenderWindow& window)
{
	if (Menu.IsInMenu())
	{
		//Menu display
		window.clear();
		window.draw(Menu.Title());
		window.draw(Menu.Welcome());
		window.draw(Menu.Play());
		window.draw(Menu.Exit());
		window.display();
		//Game reset
		if (State.ToReset())
		{
			Board.Generate_Board(State);
			Board.LoadTextures(State);
			State.GamestateReset();
		}
	}
	else 
	{
		if (State.state() == !2)
		{
			//Game display
			window.clear();
			for (int i = 0; i < State.GetNumOfCards(); i++)
				Board.ReturnBoard().at(i).drawCard(window);
			window.display();
			//StateCheck
			State.CheckGameState(Board);
			if (State.state() == 1)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(625));
				Board.resolve(State.CheckCards());
			}
		}
		else
		{
			//End screen
			window.draw(Menu.EndMsg());
			Menu.setScore(State.getScore());
			window.draw(Menu.Score());
			window.draw(Menu.Return2Menu());
			window.display();
		}
	}
}		

float game::GetWinX()
{
	return dimensions[0];
}
float game::GetWinY()
{
	return dimensions[1];
}
float game::GetViewX()
{
	return dimensions[2];
}
float game::GetViewY()
{
	return dimensions[3];
}
