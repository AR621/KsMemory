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
	void SetBoardWidth(int);
	void Generate_Board(gamestate);
	void Debug(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<card> ReturnBoard();
	int ClickCheck(int, int, int);
	void SaveRevealedCard(int);
	void reveal(int);
	void resolve(bool);
	void LoadTextures(gamestate);
};
#endif
