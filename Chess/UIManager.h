#pragma once
#include "DEFINITIONS.h"
#include <map>
#include <string>
#include "Typedefs.h"
	
class UIManager
{
public: 
	UIManager() = default;
	UIManager(WindowRef);
	~UIManager() = default;

	UIManager(const UIManager&);
	void DrawValidSquares(const ValidMoves&, Table);
	void DrawValidSquaresTeam(const Places&, int);
	void DrawCheck(const Position&);
	void setRedSquarePosition(const Position&);
	void Update();
	void Draw();
private:
	void initHoverSquare();
	void initRedQuare();
	WindowRef _window;
	sf::RectangleShape hoverSquare;
	sf::RectangleShape redSquare;
};

