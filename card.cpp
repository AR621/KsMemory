#include "card.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

card::card()
{
	card::id = -1;
	card::revealed = false;
	Card = sf::RectangleShape(sf::Vector2f(120.0f, 180.0f));
	Card.setFillColor(sf::Color(123,123,0));
}

card::~card()
{}

bool card::GetState()
{
	return revealed;
}

void card::reveal()
{
	this->revealed = true;
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
