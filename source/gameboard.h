#ifndef GAMEBOARD_H_
#define	GAMEBOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "card.h"

class gamestate;

class gameboard : public card
{
private:
	int BoardWidth = 10;
	std::vector<card> board;
	gamestate *state_ptr;
	std::vector<int> RevealedNum;
public:
	int GetBoardWidth();
	void Generate_Board(gamestate);
	//void Debug(int);//Shows in console card id placement for easier bug checking
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<card> ReturnBoard();
	int ClickCheck(int, int, int, float[]);
	void SaveRevealedCard(int);//Saves revealed card position on the board
	void reveal(int);
	void resolve(bool);//Hides or keeps revealed currently revealed pair of card depending on bool input
	void LoadTextures(gamestate);
};
#endif
