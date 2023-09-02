#pragma once
#include "SFML/Graphics.hpp"

class MessageBox
{
public:
	MessageBox() = default;
	void Init(const sf::FloatRect&, float, const sf::Color&, const sf::Color&, float);
	void Display();
protected:
	void InitBox(const sf::FloatRect&, float, const sf::Color&);
	void SetCircles(const sf::FloatRect&, float, const sf::Color&, const sf::Color&, float);
	void SetOutlines(const sf::FloatRect&, float, const sf::Color&, float);
	void SetText(const std::string&, const sf::Color&, unsigned int);
	void SetTextPosition(const sf::Vector2f&);

	sf::ConvexShape box;
	sf::CircleShape edges[4];
	sf::RectangleShape outlines[4];
	sf::Text message; 
	sf::Font font;
};

