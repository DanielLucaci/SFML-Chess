#pragma once
#include "DEFINITIONS.h"
#include <map>
#include <string>
#include "Typedefs.h"
	
class UIManager
{
public: 
	~UIManager();
	UIManager(const UIManager&) = delete;

	static UIManager* getUIManager();

	void DrawValidSquares(const ValidMoves&, Table);
	void DrawValidSquaresTeam(const Places&, int);
	void DrawCheck(const Position&);
	void setRedSquarePosition(const Position&);
	void Update();
	void Draw();
private:
	UIManager();
	void initHoverSquare();
	void initRedQuare();

	static UIManager* _instance;
	sf::RectangleShape hoverSquare;
	sf::RectangleShape redSquare;
};

extern UIManager* const uiManager;