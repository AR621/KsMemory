#include "menu.h"
#include <vector>

menu::menu()
{
	printf("Menu initialised.\n");
	//Text format
	if (!font.loadFromFile("Res/Fonts/Roboto-Black.ttf"))
		printf("Error while loading font from file\n");
	title.setFont(font);
       	title.setCharacterSize(128);
	title.setFillColor(sf::Color::Yellow);
	title.setStyle(sf::Text::Bold);
	
	welcome.setFont(font);
	welcome.setCharacterSize(24);
	welcome.setFillColor(sf::Color::Yellow);

	play.setFont(font);
       	play.setCharacterSize(72);
	play.setFillColor(sf::Color::Green);

	exit.setFont(font);
       	exit.setCharacterSize(72);
	exit.setFillColor(sf::Color::Blue);
	//Setting text
	title.setString("KsMemory");
	welcome.setString("Welcome to...");
	play.setString("Play");
	exit.setString("Exit");
	//Layout
	title.setPosition(450, 75);
	welcome.setPosition(435, 70);
	play.setPosition(675, 325);
	exit.setPosition(675, 525);
}

menu::~menu(){}

sf::Text menu::Title()
{
	return this->title;
}

sf::Text menu::Welcome()
{
	return this->welcome;
}

sf::Text menu::Play()
{
	return this->play;
}

sf::Text menu::Exit()
{
	return this->exit;
}
