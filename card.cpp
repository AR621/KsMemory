#include "card.h"
#include <iostream>
#include <vector>

card::card()
{
	card::id = -1;
	card::revealed = false;
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
