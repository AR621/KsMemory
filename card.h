#ifndef CARD_H_
#define CARD_H_

#include <SFML/Graphics.hpp>

class card : public sf::Drawable
{
private:
	int id;
	int state; //0 - hidden; 1 - revealed; 2 - keep revealed
	sf::RectangleShape Card;
	sf::Texture Texture;
	sf::Texture backTex;
public:
	card();
	~card();
	int GetState();
	int GetId();
	void reveal();
	void hide();
	void keep();
	void SetId(int);
	void setPosition(float,float);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawCard(sf::RenderWindow&);
	void LoadTextures();
};
#endif
