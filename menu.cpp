#include "menu.h"
#include <vector>

menu::menu()
{
	displayMenu = true;
	//Initialising popup
	Popup = sf::RectangleShape(sf::Vector2f(250, 300));
	if (!Popuptxt.loadFromFile("Res/Textures/EscapePopup.png"))
		printf("Error while loading popup texture\n");
	Popup.setTexture(&Popuptxt);
	Popup.setPosition(615 , 300);
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

	printf("Menu initialised.\n");
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

bool menu::IsInMenu()
{
	return displayMenu;
}

void menu::ToMenu()
{
	this->displayMenu = true;
}

void menu::StartGame()
{
	this->displayMenu = false;
}

int menu::MenuClickCheck(int x, int y, float windowDim[3])
{
	float Rx = windowDim[0] / windowDim[2], Ry = windowDim[1] / windowDim[3];
	//Rx and Ry for scaling click detection parameters in case of a window resize
	if ((x > 675*Rx && x < 825*Rx) && (y > 325*Ry && y < 410*Ry))
		return 1;
	else if ((x > 625*Rx && x < 855*Rx) && (y > 525*Ry && y < 610*Ry))
		return 2;
	else
		return 0;
}

void menu::drawPopup(sf::RenderWindow &window)
{
	window.draw(Popup);
}

int menu::PopupClickCheck(int x, int y, float windowDim[3])
{
	float Rx = windowDim[0] / windowDim[2], Ry = windowDim[1] / windowDim[3];
	//Rx and Ry for scaling click detection parameters in case of a window resize
	if ((x > 625*Rx && x < 855*Rx) && (y > 310*Ry && y < 390*Ry))
		return 1;
	else if ((x > 625*Rx && x < 855*Rx) && (y > 410*Ry && y < 510*Ry))
		return 2;
	else if ((x > 625*Rx && x < 855*Rx) && (y > 510*Ry && y < 590*Ry))
		return 3;
	else
		return 0;

}
