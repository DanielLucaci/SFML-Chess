#pragma once
#include "MessageBox.h"

class BlackWinsBox : public MessageBox {
public:
	BlackWinsBox(GameDataRef data) : MessageBox(data) {
		this->Init(sf::FloatRect(150, 200, 300, 200), 30, sf::Color(243, 240, 151), sf::Color(145, 242, 180), 15);
		this->SetText("BLACK WINS!", sf::Color::Black, 36);
		this->SetTextPosition(sf::Vector2f(300.f, 290.f));
	}
};