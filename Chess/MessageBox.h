#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"

class MessageBox
{
public:
	MessageBox(GameDataRef);
	void Init(const sf::FloatRect&, float, const sf::Color&, const sf::Color&, float);
	void Display(WindowRef);
protected:
	void InitBox(const sf::FloatRect&, float, const sf::Color&);
	void SetCircles(const sf::FloatRect&, float, const sf::Color&, const sf::Color&, float);
	void SetOutlines(const sf::FloatRect&, float, const sf::Color&, float);
	void SetText(const std::string&, const sf::Color&, unsigned int);
	void SetTextPosition(const sf::Vector2f&);

	GameDataRef _data;
	sf::ConvexShape box;
	sf::CircleShape edges[4];
	sf::RectangleShape outlines[4];
	sf::Text message; 
	sf::Font font;
};

