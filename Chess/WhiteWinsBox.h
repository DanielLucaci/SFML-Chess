#pragma once
#include "MessageBox.h"

class WhiteWinsBox : public MessageBox {
public:
    WhiteWinsBox() : MessageBox() {
        this->Init(sf::FloatRect(150, 200, 300, 200), 30, sf::Color(243, 240, 151), sf::Color(145, 242, 180), 15);
        this->SetText("WHITE WINS!", sf::Color(55, 55, 55, 127), 36);
        this->SetTextPosition(sf::Vector2f(600 / 2.f, 600 / 2.f - 10.f));
    }
};