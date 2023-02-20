#include "Utils.h"
#include <iostream>
#include <cmath>
#include "PieceManager.h"

bool Utils::isWhitePiece(int id) {
	return (id >= 1 && id <= 16) || (id >= 33 && id <= 40);
}

bool Utils::isBlackPiece(int id) {
	return (id >= 17 && id <= 32) || (id >= 41 && id <= 48);
}

bool Utils::isWhiteKing(int id) {
	return id == 13;
}

bool Utils::isBlackKing(int id) {
	return id == 29;
}

bool Utils::isKing(int id) {
	return isBlackKing(id) || isWhiteKing(id);
}

bool Utils::isWhitePawn(int id) {
	return (id >= 1 && id <= 8);
}

bool Utils::isBlackPawn(int id) {
	return (id >= 17 && id <= 24);
}

bool Utils::isFreeSpace(Position pos, Table table) {
	return table[pos.x][pos.y] == 0;
}

int Utils::getPieceAt(Position pos, Table table) {
		return !Utils::IsValid(pos) ? 0 : table[pos.x][pos.y];
}

bool Utils::isPlaceProtected(Position pos, const Places& places) {
	return std::count(places.begin(), places.end(), pos);
}

bool Utils::isPieceProtected(int id, const PieceIds& PieceIds) {
	return std::count(PieceIds.begin(), PieceIds.end(), id);
}

Position Utils::getClickedSquare(WindowRef window) {
	Position pos = sf::Mouse::getPosition(*window) / 75;
	return Position(7 - pos.y, pos.x);
}

bool Utils::isValidPiece(int turn, int id) {
	switch (turn) {
	case 0: // White
		return isWhitePiece(id);
	case 1: // Black
		return isBlackPiece(id);
	default:
		return false;
	}
}

void Utils::SetTablePosition(Table table, const Position& pos, int id) {
	table[pos.x][pos.y] = id;
}

double Utils::Distance(Position p1, Position p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool Utils::IsBetween(Position p1, Position p2, Position p3) {
	return abs(Distance(p1, p3) + Distance(p2, p3) - Distance(p1, p2)) < 0.01;
}

bool Utils::IsValid(Position pos) {
	return (pos.x >= 0 && pos.x <= 7 && pos.y >= 0 && pos.y <= 7);
}

void Utils::UpdatePosition(Position& pos, Position dir) {
	pos.x += dir.x;
	pos.y += dir.y;
}

Position Utils::GetKingPosition(int id) {
	if (Utils::isWhitePiece(id))
		return PieceManager::GetPieceMap().at(13)->GetPosition();
	return PieceManager::GetPieceMap().at(29)->GetPosition();
}