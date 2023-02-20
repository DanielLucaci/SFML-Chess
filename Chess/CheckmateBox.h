#pragma once
#include "MessageBox.h"

class CheckmateBox : public MessageBox {
public:
	CheckmateBox(GameDataRef data) : MessageBox(data) {
		this->Init(sf::FloatRect(150, 200, 300, 200), 30, sf::Color(243, 240, 151), sf::Color(145, 242, 180), 15);
		this->SetText("CHECKMATE", sf::Color::Red, 24);
		this->SetTextPosition(sf::Vector2f(600 / 2.f, 600 / 2.f));
	}
};