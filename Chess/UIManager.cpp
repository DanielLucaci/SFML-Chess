#include "UIManager.h"
#include "Move.h"
#include "Utils.h"
#include "WindowManager.h"

UIManager* UIManager::_instance = nullptr;

UIManager* const uiManager = UIManager::getUIManager();

UIManager::UIManager()
{
	this->initHoverSquare();
	this->initRedQuare();
}

UIManager::~UIManager() {
	if (_instance != nullptr)
		delete(_instance);
}

UIManager* UIManager::getUIManager() {
	if (_instance == nullptr) {
		_instance = new UIManager();
	}
	return _instance;
}

void UIManager::setRedSquarePosition(const Position& pos)
{
	this->redSquare.setPosition(sf::Vector2f(75.f * pos.y, 75.f * (7 - pos.x)));
}

void UIManager::Update()
{
	Position mousePos = sf::Mouse::getPosition(*window);
	int row = mousePos.x / 75;
	int column = mousePos.y / 75;
	this->hoverSquare.setPosition((float)row * 75.f + 5.f, (float)column*75.f + 5.f);
}

void UIManager::DrawValidSquares(const ValidMoves& moves, Table table) {
	for (Move* move : moves) {
		
		Position pos = move->GetActualPosition();
		sf::RectangleShape rect(sf::Vector2f(65.f, 65.f));

		switch (move->GetType()) {
			case MoveType::CAPTURE:
			case MoveType::ENPASSANT:
				rect.setFillColor(sf::Color(216, 0, 0)); // RED
				break;
			case MoveType::CASTLE:
				rect.setFillColor(sf::Color(30, 144, 255)); // BLUE
				break;
			case MoveType::NORMAL:
				rect.setFillColor(sf::Color(86, 255, 0)); // GREEN
				break;
			case MoveType::TRANSFORM:
				if(!Utils::getPieceAt(pos, table))
					rect.setFillColor(sf::Color(86, 255, 0)); // GREEN
				else
					rect.setFillColor(sf::Color(216, 0, 0)); // RED
				break;
			default:
				break;
		}
		rect.setPosition(75.f * pos.y + 5.f, 75.f * (7 - pos.x) + 5.f);
		window->draw(rect);
	}
}

void UIManager::DrawValidSquaresTeam(const Places& places, int teamNr)
{
	sf::Color color = (teamNr == 0) ? sf::Color::White : sf::Color::Black;
	for (Position pos : places) {

		sf::RectangleShape transparentRect(sf::Vector2f(65.f, 65.f));
		transparentRect.setFillColor(sf::Color::Transparent); 
		transparentRect.setPosition(75.f * pos.y + 5.f, 75.f * (7 - pos.x) + 5.f);
		transparentRect.setOutlineThickness(5.f);
		transparentRect.setOutlineColor(color);
		window->draw(transparentRect);
	}
}

void UIManager::DrawCheck(const Position& pos)
{
	sf::RectangleShape rect(sf::Vector2f(75.f, 75.f));
	rect.setPosition(pos.y * 75.f, (7 - pos.x) * 75.f);
	rect.setFillColor(sf::Color(220, 20, 60));
	window->draw(rect);
}

void UIManager::Draw()
{
	window->draw(hoverSquare);
	window->draw(redSquare);
}


void UIManager::initHoverSquare()
{
	this->hoverSquare.setPosition(-100, -100);
	this->hoverSquare.setSize(sf::Vector2f(65, 65));
	this->hoverSquare.setFillColor(sf::Color::Transparent);
	this->hoverSquare.setOutlineThickness(5);
	this->hoverSquare.setOutlineColor(sf::Color(82, 58, 40));
}

void UIManager::initRedQuare()
{
	this->redSquare.setFillColor(sf::Color(255, 37, 17));
	this->redSquare.setSize(sf::Vector2f(75, 75));
	this->redSquare.setPosition(-100, -100);
}
