#include "card.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

card::card()
{
	card::id = -1;
	card::state = 0;
	Card = sf::RectangleShape(sf::Vector2f(120.0f, 180.0f));
	back.loadFromFile("Back.PNG");
	Card.setTexture(&back);
}

card::~card(){}

int card::GetState()
{
	return state;
}

void card::reveal()
{
	this->state = 1;	
	Card.setFillColor(sf::Color(50,50,50));
}

void card::hide()
{
	this->state = 0;
	Card.setFillColor(sf::Color(123,123,0));
}

void card::keep()
{
	this->state = 2;
}

int card::GetId()
{
	return id;
}

void card::SetId(int new_id)
{
	this->id = new_id;
}

void card::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw (Card, states);
}

sf::RectangleShape card::passcard()
{
	return this->Card;
}

void card::setPosition(float x, float y)
{
	this->Card.setPosition(x, y);
}
