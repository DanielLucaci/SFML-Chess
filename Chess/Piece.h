#pragma once
#include "SFML/Graphics.hpp"
#include "GameData.h"
#include "Utils.h"
#include "Typedefs.h"

enum class PieceType {
	PAWN,
	KNIGHT,
	ROOK,
	KING,
	QUEEN,
	BISHOP
};

class Piece
{
public:
	Piece() = default;
	Piece(GameDataRef, const Position&, int, PieceType);

	const sf::Sprite& GetTexture() const;

	const Position& GetPosition() const;
	void SetPosition(const Position&);

	int GetId() const;
	
	bool GetMoved() const;
	void SetMoved(bool moved = true);

	bool GetCheck() const;
	void SetCheck(bool check = true);

	bool GetCaptured() const;
	void SetCaptured(bool = true);

	void SetLockingPiece(Piece*);
	Piece* GetLockingPiece();

	void SetLockedPiece(Piece*);
	Piece* GetLockedPiece();

	const PieceType& GetPieceType() const;

	ValidMoves& GetValidMoves();
	void AddValidMove(Move*);


	bool canMakeMove(Position pos);

	Piece& operator =(const Piece&);

	virtual void Update(Table) = 0;
	void Clear();
	void Draw(); 
	bool protect(const Position&, Table) const;
	bool attack(const Position&, Table) const;
	bool isCheck(const Position&, Table) const;

protected:
	void UpdatePiecePosition();
	Position position;
	int id;

	PieceType type;
	ValidMoves validMoves;
	Piece* lockingPiece;
	Piece* lockedPiece;
	bool check, moved, captured;
	GameDataRef _data;
	sf::Sprite texture;
};

typedef std::map<int, Piece*> PieceMap;

