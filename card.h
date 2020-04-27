#ifndef CARD_H_
#define CARD_H_

#include <SFML/Graphics.hpp>

class card : public sf::Drawable
{
private:
	int id;
	bool revealed;
public:
	card();
	~card();
	bool GetState();
	void reveal();
	int GetId();
	void SetId(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
