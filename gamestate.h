#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class gamestate {
private:
	int unique_id_pool[29];
	int roll_count;
	int num_of_cards = 30;
	bool game_won;	
public:
	gamestate();
	~gamestate();
	bool Check_If_Id_Free(int);
	void Decrement(int);
	int GetRoll_count();
	int Generate_Id();
	int GetNumOfCards();
	void SetNumOfCards(int);
};
#endif
