#pragma once
#include "MessageBox.h"
#include "TransformMove.h"

class TransformBox : public MessageBox {
public:
	TransformBox(): MessageBox(), _turn(0) {
		this->Init(sf::FloatRect(105, 200, 390, 200), 10, sf::Color(237, 226, 212), sf::Color(89, 85, 83), 4);
		this->SetText("CHOOSE A PIECE", sf::Color(1, 77, 156), 20);
		this->SetTextPosition(sf::Vector2f(300, 250));
		this->pieceType = TransformedPieceType::NOPIECE;
	}

	void SetTurn(int turn);
	void HandleInput();
	void Update(float dt);
	void Display();
	void LoadTextures();
	TransformedPieceType GetChosenPiece() const;
private:
	sf::Sprite _knight, _bishop, _rook, _queen;
	sf::RectangleShape _shape;
	TransformedPieceType pieceType;
	int _turn;
};