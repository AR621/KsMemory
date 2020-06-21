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
	bool Check_If_Id_Free(int);//To avoid more than two card of same id
	void Decrement(int);//Decrements specific position in unique_id_pool array
	int GetRoll_count();
	int Generate_Id();//both functions used in random id generation
	int GetNumOfCards();
	void SetNumOfCards(int);
	void CheckGameState(gameboard);
	int state();//returns state of the game
	void SaveRevealedCard(int);//Saves card id for comparison
	bool CheckCards();//Check if cards match
	bool ToReset();//Sets restart to true
	void ResetGame();//Resets the game state
	int getScore();
};
#endif
