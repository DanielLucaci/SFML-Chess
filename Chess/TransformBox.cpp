#include "TransformBox.h"
#include "WindowManager.h"
#include "AssetManager.h"
#include "InputManager.h"

void TransformBox::LoadTextures()
{
	this->_shape.setFillColor(sf::Color(250, 250, 210));
	this->_shape.setSize(sf::Vector2f(80., 80.));
	this->_shape.setPosition(135, 290);
	switch (this->_turn) {
	case 0:
		this->_knight = sf::Sprite(assetManager->GetTexture("White Knight"));
		this->_bishop = sf::Sprite(assetManager->GetTexture("White Bishop"));
		this->_rook = sf::Sprite(assetManager->GetTexture("White Rook"));
		this->_queen = sf::Sprite(assetManager->GetTexture("White Queen"));
		break;
	case 1:
		this->_knight = sf::Sprite(assetManager->GetTexture("Black Knight"));
		this->_bishop = sf::Sprite(assetManager->GetTexture("Black Bishop"));
		this->_rook = sf::Sprite(assetManager->GetTexture("Black Rook"));
		this->_queen = sf::Sprite(assetManager->GetTexture("Black Queen"));
		break;
	default:
		break;
	}

	this->_knight.setPosition(145, 300);
	this->_bishop.setPosition(235, 300);
	this->_rook.setPosition(325, 300);
	this->_queen.setPosition(415, 300);
}

TransformedPieceType TransformBox::GetChosenPiece() const
{
	return this->pieceType;
}

void TransformBox::SetTurn(int turn)
{
	this->_turn = turn;
}

void TransformBox::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (inputManager->isSpriteClicked(this->_bishop, sf::Mouse::Left)) 
				this->pieceType = TransformedPieceType::BISHOP;
			
			else if (inputManager->isSpriteClicked(this->_knight, sf::Mouse::Left)) 
				this->pieceType = TransformedPieceType::KNIGHT;
			
			else if (inputManager->isSpriteClicked(this->_rook, sf::Mouse::Left)) 
				this->pieceType = TransformedPieceType::ROOK;
			
			else if (inputManager->isSpriteClicked(this->_queen, sf::Mouse::Left)) 
				this->pieceType = TransformedPieceType::QUEEN;

			break;
		default:
			break;
		}
	}
}

void TransformBox::Update(float dt)
{
	if (inputManager->isSpriteHovered(this->_knight))
		this->_shape.setPosition(135, 290);

	else if (inputManager->isSpriteHovered(this->_bishop))
		this->_shape.setPosition(225, 290);

	else if (inputManager->isSpriteHovered(this->_rook))
		this->_shape.setPosition(315, 290);
	
	else if (inputManager->isSpriteHovered(this->_queen)) 
		this->_shape.setPosition(405, 290);
	
}

void TransformBox::Display()
{
	MessageBox::Display();
	window->draw(this->_shape);
	window->draw(this->_knight);
	window->draw(this->_bishop);
	window->draw(this->_rook);
	window->draw(this->_queen);
}