#include "menu.h"
#include <vector>

menu::menu()
{
	displayMenu = true;
	//MENU
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
	//Initialising popup
	Popup = sf::RectangleShape(sf::Vector2f(250, 300));
	if (!Popuptxt.loadFromFile("Res/Textures/EscapePopup.png"))
		printf("Error while loading popup texture\n");
	Popup.setTexture(&Popuptxt);
	Popup.setPosition(615 , 300);
	//Initialising end screen
	//Layout
	winMsg.setPosition(425, 225);
	score.setPosition(60, 775);
	return2Menu.setPosition(1115, 775);
	//Setting text
	winMsg.setString("Game won!");
	winMsg.setFont(font);
       	winMsg.setCharacterSize(128);
	winMsg.setFillColor(sf::Color::Green);

	scoreMsg = "Number of wrong compares: ";
	score.setString(scoreMsg);
	score.setFont(font);
       	score.setCharacterSize(48);
	score.setFillColor(sf::Color::Yellow);

	return2Menu.setString("Return to menu");
	return2Menu.setFont(font);
       	return2Menu.setCharacterSize(48);
	return2Menu.setFillColor(sf::Color::Blue);
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

sf::Text menu::EndMsg()
{
	return this->winMsg;
}

sf::Text menu::Score()
{
	return this->score;
}

sf::Text menu::Return2Menu()
{
	return this->return2Menu;
}

void menu::setScore(int newScore)
{
	scoreMsg = "Number of wrong compares: " + std::to_string(newScore - 15);
	score.setString(scoreMsg);	
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

int menu::EndClickCheck(int x, int y, float windowDim[3])
{
	float Rx = windowDim[0] / windowDim[2], Ry = windowDim[1] / windowDim[3];
	//Rx and Ry for scaling click detection parameters in case of a window resize
	if ((x > 1110*Rx && x < 1400*Rx) && (y > 770*Ry && y < 880*Ry))
		return 1;
	else
		return 0;
}
