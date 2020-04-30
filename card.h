#ifndef CARD_H_
#define CARD_H_

#include <SFML/Graphics.hpp>

class card : public sf::Drawable
{
private:
	int id;
	int state; //0 - hidden; 1 - revealed; 2 - keep revealed
	sf::RectangleShape Card;
	sf::Texture back;
public:
	card();
	~card();
	int GetState();
	void reveal();
	void hide();
	void keep();
	int GetId();
	void SetId(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape passcard();
	void setPosition(float,float);
};
#endif
