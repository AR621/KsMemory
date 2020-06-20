#ifndef GAME_H_
#define GAME_H_

#include "menu.h"
#include "gamestate.h"
#include "gameboard.h"

class game 
{
private:
	bool menuScreen = true;
	float dimensions[4] = {1024.0, 600.0, 1480.0, dimensions[1] * dimensions[2] / dimensions[0] };
	menu Menu;
	gamestate State;
	gameboard Board;
public:	
	game();
	~game();
	//Game code
	void UpdateWinSize(sf::RenderWindow&);
	void HandleMouseClicks(sf::RenderWindow&, sf::Event);
	void Display(sf::RenderWindow&);
	//Getters
	float GetWinX();
	float GetWinY();
	float GetViewX();
	float GetViewY();
};
#endif
