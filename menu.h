#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include <SFML/Graphics.hpp>


class menu
{
private:
	sf::RectangleShape Popup;
	sf::Texture Popuptxt;
	bool displayMenu;
	sf::Font font;
	sf::Text title;
	sf::Text welcome;
	sf::Text play;
	sf::Text exit;
public:
	menu();
	~menu();
	sf::Text Title();
	sf::Text Welcome();
	sf::Text Play();
	sf::Text Exit();
	bool IsInMenu();
	void ToMenu();
	void StartGame();
	int MenuClickCheck(int, int, float[3]);
	void drawPopup(sf::RenderWindow&);
	int PopupClickCheck(int, int, float[3]);
};
#endif

