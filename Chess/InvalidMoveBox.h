#pragma once
#include "MessageBox.h"

class InvalidMoveBox : public MessageBox {
public:
	InvalidMoveBox() : MessageBox() {
		this->Init(sf::FloatRect(50, 500, 150, 50), 10, sf::Color(237, 226, 212), sf::Color(89, 85, 83), 4);
		this->SetText("INVALID MOVE", sf::Color(1, 77, 156), 18);
		this->SetTextPosition(sf::Vector2f(125, 520));
	}
};