#include "gamestate.h"
#include <iostream>
#include <ctime>
#include "gameboard.h"

gamestate::gamestate()
{
	for (int i = 0; i < num_of_cards; i++)
		gamestate::unique_id_pool[i] = 2;
	roll_count = 1;
	GameState = 0;
	CurrentlyRevealed = 0;
	std::cout << "gamestate successfully initialised\n";
}

gamestate::~gamestate(){}

bool gamestate::Check_If_Id_Free(int id)
{
	if (this->unique_id_pool[id] > 0)
		return true;
	return false;
}

void gamestate::Decrement(int card_num)
{
	if (gamestate::unique_id_pool[card_num] > 0)
		gamestate::unique_id_pool[card_num]--;
	else
		std::cout << "Unexpected error - pool depleted\n";
}

int gamestate::GetRoll_count()
{
	return this->roll_count;
}

int gamestate::Generate_Id()
{
	srand (time(0));
	while (bool generating = true)
	{
		int new_id;
		for (int i = 0; i < roll_count; i++)
			new_id = rand() % num_of_cards / 2 + 1;
		roll_count++;
		if(Check_If_Id_Free(new_id))
		{
			Decrement(new_id);
			generating = false;
			return new_id;
		}
	}
	return -1;
}

int gamestate::GetNumOfCards()
{
	return this->num_of_cards;
}

void gamestate::SetNumOfCards(int new_value)
{
	this->num_of_cards = new_value;
}

void gamestate::CheckGameState(gameboard Board)
{
	this->CurrentlyRevealed = 0;
	for (int i = 0; i < num_of_cards; i++)
	{
	int CardState = Board.ReturnBoard().at(i).GetState();
		if (CardState != 2)
		{
			if (CurrentlyRevealed == 2)
				this->GameState = 1;
			else if (CardState == 1)
				this->CurrentlyRevealed++;
			else
				this->GameState = 0;
		}
		else
			this->GameState = 2;
	}
}

int gamestate::state()
{
	return this->GameState;
}

void gamestate::SaveRevealedCard(int CardId)
{
	this->RevealedIds.push_back(CardId
);
}

bool gamestate::CheckCards()
{
	if (RevealedIds.at(0) == RevealedIds.at(1))
		{
			this->GameState = 0;
			RevealedIds.clear(); 

			return true;
		}
	else
		{
			this->GameState = 0;
			RevealedIds.clear(); 
			return false;
		}
}
