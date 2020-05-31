#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <vector>
#include "gameboard.h"

class gamestate 
{
private:
	bool restart;
	int unique_id_pool[29];
	int roll_count;
	int num_of_cards = 30;
	int CurrentlyRevealed;
	int RevealedPairs = 0;
	int GameState; //0 - Default ;1 - Card check;2 - Game won
	std::vector<int> RevealedIds;
	int NumbOfCompares;
public:
	gamestate();
	~gamestate();
	void GamestateReset();
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
	bool ToReset();
	void ResetGame();
	int getScore();
};
#endif
