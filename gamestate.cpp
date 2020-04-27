#include "gamestate.h"
#include <iostream>
#include <ctime>

gamestate::gamestate()
{
	for (int i = 0; i < num_of_cards; i++)
		gamestate::unique_id_pool[i] = 2;
	game_won = false;
	roll_count = 1;
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
