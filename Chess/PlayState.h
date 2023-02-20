#pragma once
#include "State.h"
#include "GameData.h"
#include "Team.h"
#include "PieceManager.h"
#include "SoundManager.h"
#include "MessageBox.h"
#include "BoxManager.h"
#include "TransformBox.h"


class PlayState: public State
{
public:
	PlayState(GameDataRef);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	void DrawPieces();
	void DrawBoard();
	int GetTurn() const;
private:
	void ReadTable();
	void PrintTable();
	void InitTable();
	void MovePiece(Move*);
	void makeSound(Move*);
	GameDataRef _data;

	sf::Sprite _boardTexture;
	Team* _whiteTeam;
	Team* _blackTeam;
	Move* lastMove;
	PlayStates _currentState;
	bool _isCheckmate, _isStalemate, _showMessage;
	int _turn, _selectedPiece;

	// Managers
	SoundManager _soundManager;
	PieceManager _pieceManager;
	BoxManager _boxManager;
	Table _table;

	// Clocks
	sf::Clock _elapsedTime;
	sf::Clock _elapsedTimeBox;
	bool _lockClick;

	// Box
	MessageBox* _box; 
};

