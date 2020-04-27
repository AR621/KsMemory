#include "gameboard.h"
#include "card.h"
#include "gamestate.h"
#include <iostream>

int gameboard::GetBoardWidth()
{
	return this->BoardWidth;
}
void gameboard::SetBoardWidth(int new_value)
{
	this->BoardWidth = new_value;
}
void gameboard::Generate_Board(gamestate gamestate)
{
	int num_of_cards = gamestate.GetNumOfCards();
	for (int i = 0; i < num_of_cards; i++)
	{
		card card;
		card.SetId(gamestate.Generate_Id());
		this->board.push_back(card);
	}
}
void gameboard::Display_Board(int num_of_cards)
{
	for (int i = 0; i < num_of_cards ; i++)
	{
		std::cout << board.at(i).GetId() << " : ";
		if (!((i + 1) % BoardWidth || i == 0))
			std::cout << std::endl;
	}
}
