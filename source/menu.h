#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include <SFML/Graphics.hpp>


class menu
{
private:
	//Menu
	sf::Font font;
	sf::Text title;
	sf::Text welcome;
	sf::Text play;
	sf::Text exit;
	//Popup
	sf::Texture Popuptxt;
	sf::RectangleShape Popup;
	bool displayMenu;
	//Game won screen	
	sf::Text winMsg;
	std::string scoreMsg; 
	sf::Text score;
	sf::Text return2Menu;
public:
	menu();
	~menu();
	sf::Text Title();
	sf::Text Welcome();
	sf::Text Play();
	sf::Text Exit();
	sf::Text EndMsg();
	sf::Text Score();
	sf::Text Return2Menu();
	void setScore(int);
	bool IsInMenu();
	void ToMenu();
	void StartGame();
	void drawPopup(sf::RenderWindow&);
	int MenuClickCheck(int, int, float[3]);
	int PopupClickCheck(int, int, float[3]);
	int EndClickCheck(int, int, float[3]);
};
#endif

