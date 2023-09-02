#include "TransformBox.h"
#include "GameData.h"

void TransformBox::LoadTextures()
{
	this->_shape.setFillColor(sf::Color(250, 250, 210));
	this->_shape.setSize(sf::Vector2f(80., 80.));
	this->_shape.setPosition(135, 290);
	switch (this->_turn) {
	case 0:
		this->_knight = sf::Sprite(data->assets->GetTexture("White Knight"));
		this->_bishop = sf::Sprite(data->assets->GetTexture("White Bishop"));
		this->_rook = sf::Sprite(data->assets->GetTexture("White Rook"));
		this->_queen = sf::Sprite(data->assets->GetTexture("White Queen"));
		break;
	case 1:
		this->_knight = sf::Sprite(data->assets->GetTexture("Black Knight"));
		this->_bishop = sf::Sprite(data->assets->GetTexture("Black Bishop"));
		this->_rook = sf::Sprite(data->assets->GetTexture("Black Rook"));
		this->_queen = sf::Sprite(data->assets->GetTexture("Black Queen"));
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
	while (data->window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			data->window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (data->input->isSpriteClicked(this->_bishop, sf::Mouse::Left, data->window)) 
				this->pieceType = TransformedPieceType::BISHOP;
			
			else if (data->input->isSpriteClicked(this->_knight, sf::Mouse::Left, data->window)) 
				this->pieceType = TransformedPieceType::KNIGHT;
			
			else if (data->input->isSpriteClicked(this->_rook, sf::Mouse::Left, data->window)) 
				this->pieceType = TransformedPieceType::ROOK;
			
			else if (data->input->isSpriteClicked(this->_queen, sf::Mouse::Left, data->window)) 
				this->pieceType = TransformedPieceType::QUEEN;

			break;
		default:
			break;
		}
	}
}

void TransformBox::Update(float dt)
{
	if (data->input->isSpriteHovered(this->_knight, data->window))
		this->_shape.setPosition(135, 290);

	else if (data->input->isSpriteHovered(this->_bishop, data->window))
		this->_shape.setPosition(225, 290);

	else if (data->input->isSpriteHovered(this->_rook, data->window))
		this->_shape.setPosition(315, 290);
	
	else if (data->input->isSpriteHovered(this->_queen, data->window)) 
		this->_shape.setPosition(405, 290);
	
}

void TransformBox::Display()
{
	MessageBox::Display();
	data->window->draw(this->_shape);
	data->window->draw(this->_knight);
	data->window->draw(this->_bishop);
	data->window->draw(this->_rook);
	data->window->draw(this->_queen);
}