#include "card.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

card::card()
{
	card::id = -1;
	card::state = 0;
	Card = sf::RectangleShape(sf::Vector2f(120.0f, 180.0f));
}

card::~card(){}

int card::GetState()
{
	return state;
}

void card::reveal()
{
	this->state = 1;	
	Card.setTexture(&Texture);
}

void card::hide()
{
	this->state = 0;
	Card.setTexture(&backTex);
}

void card::keep()
{
	this->state = 2;
	Card.setTexture(&Texture);
}

int card::GetId()
{
	return id;
}

void card::SetId(int new_id)
{
	this->id = new_id;
}

void card::draw(sf::RenderTarget& target, sf::RenderStates states) const{}

void card::drawCard(sf::RenderWindow &window)
{
	window.draw(Card);
}

void card::setPosition(float x, float y)
{
	this->Card.setPosition(x, y);
}

void card::LoadTextures()
{
	backTex.loadFromFile("Textures/Back.png");
	std::string path = "Textures/card" + std::to_string(id) + ".png";
	Texture.loadFromFile(path);
	Card.setTexture(&backTex);
}
