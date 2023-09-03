#pragma once
#include "DEFINITIONS.h"

class Utils
{
public:
	static bool isWhitePiece(int);
	static bool isBlackPiece(int);

	static bool isWhiteKing(int);

	static bool isBlackKing(int);

	static bool isKing(int);

	static bool isWhitePawn(int);

	static bool isBlackPawn(int);

	static bool isFreeSpace(Position, Table);

	static int getPieceAt(Position, Table);

	static bool isPlaceProtected(Position, const Places&);

	static bool isPieceProtected(int, const PieceIds&);

	static Position getClickedSquare();

	static bool isValidPiece(int, int);

	static void SetTablePosition(Table, const Position&, int = 0);

	static double Distance(Position, Position);

	static bool IsBetween(Position, Position, Position);

	static bool IsValid(Position);

	static void UpdatePosition(Position&, Position);

	static Position GetKingPosition(int);
};

