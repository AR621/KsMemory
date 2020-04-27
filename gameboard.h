#ifndef GAMEBOARD_H_
#define	GAMEBOARD_H_

#include <vector>

class card;
class gamestate;

class gameboard {
private:
	int BoardWidth = 10;
	std::vector<card> board;
	gamestate *state_ptr;
public:
	int GetBoardWidth();
	void SetBoardWidth(int);
	void Generate_Board(gamestate);
	void Display_Board(int);
};
#endif
