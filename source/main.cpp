#include "game.h"
#include <SFML/Graphics.hpp>

int main()
{
	//Initialising game & menu
	game Ksmemory;
	//Initialising window
	sf::RenderWindow window(sf::VideoMode(Ksmemory.GetWinX(), Ksmemory.GetWinY()), "KsMemory");
	sf::View view(sf::FloatRect(0, 0, Ksmemory.GetViewX(), Ksmemory.GetViewY()));
	window.setView(view);
	window.setFramerateLimit(60);
	//Game
	while (window.isOpen())
	{
		sf::Event event;
		Ksmemory.UpdateWinSize(window);	
		Ksmemory.HandleMouseClicks(window, event);
		Ksmemory.Display(window);
	}
	return 0;
}
