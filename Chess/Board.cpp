#include "Board.h"
#include <fstream>
#include <utility>

Board::Board(GameDataRef data, Team* white, Team* black) : _data(data), whiteTeam(white), blackTeam(black),overWhite(33), overBlack(41) {
	this->initTable();
	this->initPieces();
}

Board::~Board() {
	delete(this->whiteTeam);
	delete(this->blackTeam);
	for (int i = 0; i < 8; i++) {
		delete(table[i]);
	}
	delete(table);
}

const PieceMap& Board::GetPieceMap() const
{
	return this->pieceMap;
}

int Board::GetPieceIdAt(const Position& pos) const
{
	try {
		return this->table[pos.x][pos.y];
	}
	// User clicked outside the window
	catch (...) {
		return 0;
	}
}

Board::Board(const Board& other) {
	this->overWhite = other.overWhite;
	this->overBlack = other.overBlack;	
}

inline void Board::initTable() {
	this->table = new int*[8];
	for (int i = 0; i < 8; i++) {
		this->table[i] = new int[8];
	}

	std::ifstream fin("table.ini");
	int row = 0, col = 0;

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			fin >> table[row][col];
		}
	}
}

inline void Board::initPieces() {
	for (Piece* piece : whiteTeam->getPieces()) {
		this->pieceMap.insert(std::map<int, Piece*>::value_type(piece->GetId(), piece ));
	}
	
	for (Piece* piece : blackTeam->getPieces()) {
		this->pieceMap.insert(std::map<int, Piece*>::value_type(piece->GetId(), piece));
	}
}

Piece* Board::operator[](int id) const {
	return this->pieceMap.at(id);
}

Table& Board::GetTable() {
	return this->table;
}

void Board::MovePiece(Move* move)
{
	int pieceId = move->GetPieceId();
	Piece* p = this->pieceMap.at(pieceId);
	Position previous = move->GetPreviousPosition();
	Position actual = move->GetActualPosition();
	p->SetMoved(true);
	p->SetPosition(actual);
	switch (move->GetType()) {
		case MoveType::NORMAL:
			Utils::SetTablePosition(table, previous);
			Utils::SetTablePosition(table, actual, pieceId);
			break;
		case MoveType::CAPTURE:
			break;
		case MoveType::CASTLE:
			break;
		case MoveType::ENPASSANT:
			break;
		case MoveType::TRANSFORM:
			break;
		default:
			break;
	}
}
