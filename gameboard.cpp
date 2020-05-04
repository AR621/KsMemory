#include "gameboard.h"
#include "card.h"
#include "gamestate.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int gameboard::GetBoardWidth()
{
	return this->BoardWidth;
}
void gameboard::SetBoardWidth(int new_value)
{
	this->BoardWidth = new_value;
}
void gameboard::Generate_Board(gamestate gamestate)
{
	int num_of_cards = gamestate.GetNumOfCards();
	int j = -1;
	for (int i = 0; i < num_of_cards; i++)
	{
		if (!(i % BoardWidth))
			j++;
		card card;
		card.SetId(gamestate.Generate_Id());
		card.setPosition(
				30 + i % BoardWidth * 145,
				30 + j * 210);	
		this->board.push_back(card);
	}
}
void gameboard::Debug(int num_of_cards)
{
	for (int i = 0; i < num_of_cards ; i++)
	{
		std::cout << board.at(i).GetId() << " : ";
		if (!((i + 1) % BoardWidth || i == 0))
			std::cout << std::endl;
	}
}

void gameboard::draw(sf::RenderTarget& target, sf::RenderStates states) const{}

std::vector<card> gameboard::ReturnBoard()
{
	return this->board;
}

int gameboard::ClickCheck(int num_of_cards, int x, int y)
{
	for(int j = 0; j < num_of_cards / BoardWidth; j++)	
		for(int i = 0; i < BoardWidth; i++)
		{
			if(
				((x > 30 + i * 25 + i * 120) && (x < 30 + i * 25 + (i + 1) * 120))
				&&
				((y > (j + 1) * 30 + j * 180) && (y < (j + 1) * (30 + 180)))  
		)
				return i + j * 10;
		}
	return -1;
}

void gameboard::SaveRevealedCard(int CardNum)
{
	this->RevealedNum.push_back(CardNum);
}

void gameboard::reveal(int CardNum)
{
	board.at(CardNum).reveal();
}

void gameboard::resolve(bool CardMatch)
{
	if (CardMatch == false)
	{
		for (int i = 0; i < 2; i++)
			board.at(RevealedNum.at(i)).hide();
		this->RevealedNum.clear();
	}
	else
	{
		for (int i = 0; i < 2; i++)
			board.at(RevealedNum.at(i)).keep();
		this->RevealedNum.clear();
	}
}

void gameboard::LoadTextures(gamestate gamestate)
{
	for (int i = 0; i < gamestate.GetNumOfCards(); i++)
		this->board.at(i).LoadTextures();
}
