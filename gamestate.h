#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <vector>
#include "gameboard.h"

class gamestate 
{
private:
	int unique_id_pool[29];
	int roll_count;
	int num_of_cards = 30;
	int CurrentlyRevealed;
	int GameState; //0 - Default ;1 - Card check;2 - Game won
	std::vector<int> RevealedIds;
public:
	gamestate();
	~gamestate();
	bool Check_If_Id_Free(int);
	void Decrement(int);
	int GetRoll_count();
	int Generate_Id();
	int GetNumOfCards();
	void SetNumOfCards(int);
	void CheckGameState(gameboard);
	int state();
	void SaveRevealedCard(int);
	bool CheckCards();
};
#endif
