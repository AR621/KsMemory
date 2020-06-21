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
	bool Check_If_Id_Free(int);//To avoid more than two card os same id
	void Decrement(int);//Decrements unique_id_pool array
	int GetRoll_count();
	int Generate_Id();//both functions used in random id generation
	int GetNumOfCards();
	void SetNumOfCards(int);
	void CheckGameState(gameboard);
	int state();//returns state of the game
	void SaveRevealedCard(int);//Saces card id for comparison
	bool CheckCards();//Check if cards match
	bool ToReset();//set Restart to true
	void ResetGame();//resets the game state
	int getScore();
};
#endif
