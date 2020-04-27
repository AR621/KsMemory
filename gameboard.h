#ifndef GAMEBOARD_H_
#define	GAMEBOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>

class card;
class gamestate;

class gameboard : public sf::Drawable
{
private:
	int BoardWidth = 10;
	std::vector<card> board;
	gamestate *state_ptr;
public:
	int GetBoardWidth();
	void SetBoardWidth(int);
	void Generate_Board(gamestate);
	void Debug(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<card> ReturnBoard();
	int ClickCheck(int, int, int);
};
#endif
