#include "Piece.h"
#include <iostream>
#include "WindowManager.h"

Piece::Piece(const Position& pos, int id, PieceType type):
	position(pos),
	id(id),
	check(false),
	moved(false),
	captured(false),
	type(type),
	lockingPiece(nullptr),
	lockedPiece(nullptr)
{
}

const sf::Sprite& Piece::GetTexture() const {
	return this->texture;
}

void Piece::SetPosition(const Position& pos){
	this->position = pos;
	this->UpdatePiecePosition();
}

const Position& Piece::GetPosition() const
{
	return this->position;
}

void Piece::UpdatePiecePosition() {
	this->texture.setPosition(
		static_cast<int>(this->position.y * 75 + PIECE_OFFSET), 
		static_cast<int>((7 - this->position.x) * 75 + PIECE_OFFSET)
	);
}

int Piece::GetId() const
{
	return this->id;
}

bool Piece::GetMoved() const
{
	return this->moved;
}

void Piece::SetMoved(bool moved)
{
	this->moved = moved;
}

bool Piece::GetCheck() const 
{
	return this->check;
}

void Piece::SetCheck(bool check) 
{
	this->check = check;
}

bool Piece::GetCaptured() const {
	return this->captured;
}

void Piece::SetCaptured(bool captured) {
	this->captured = captured;
}

void Piece::SetLockingPiece(Piece* p)
{	
	this->lockingPiece = p;
}

Piece* Piece::GetLockingPiece()
{
	return this->lockingPiece;
}

void Piece::SetLockedPiece(Piece* p)
{
	this->lockedPiece = p;
}

Piece* Piece::GetLockedPiece()
{
	return this->lockedPiece;
}

const PieceType& Piece::GetPieceType() const
{
	return this->type;
}


ValidMoves& Piece::GetValidMoves()
{
	return this->validMoves;
}

void Piece::AddValidMove(Move* move) {
	this->validMoves.push_back(move);
}

void Piece::Clear()
{
	this->validMoves.clear();
	this->check = false;
	if (this->lockedPiece != nullptr) {
		this->lockedPiece->SetLockingPiece(nullptr);
		this->SetLockedPiece(nullptr);
	}
}

void Piece::Draw() {
	window->draw(this->texture);
}

bool Piece::canMakeMove(Position pos)
{
	if (this->lockingPiece == nullptr)
		return true;

	if (Utils::IsBetween(
		this->lockingPiece->GetPosition(),
		Utils::GetKingPosition(this->id),
		pos)) {
		return true;
		
	}
	return false;
}

Piece& Piece::operator=(const Piece& other) {
	if (this == &other) {
		return *this;
	}

	this->id = other.GetId();
	this->position = other.GetPosition();
	this->check = other.GetCheck();
	this->moved = other.GetMoved();
	return *this;
}

bool Piece::protect(const Position& pos, Table table) const {
	/*
		Checks if the current piece protects the piece on position (x,y)
		x - row position
		y - column position
		m - table with information about PieceIds position
		Returns true if the piece is protected, false otherwise
	*/
	int pieceId = table[pos.x][pos.y];
	if (Utils::isWhitePiece(this->id)) {
		return Utils::isWhitePiece(pieceId) && !Utils::isWhiteKing(pieceId);
	}
	else {
		return Utils::isBlackPiece(pieceId) && !Utils::isBlackKing(pieceId);
	}
}

bool Piece::attack(const Position& pos, Table table) const {
	/*
		Checks if the current piece attacks the piece on position (x,y)
		x - row number of current piece
		y - column number of current piece
		m - table with information about PieceIds position
		Returns true if the piece is attacked, false otherwise
	*/
	int pieceId = table[pos.x][pos.y];
	if (Utils::isWhitePiece(this->id)) {
		return Utils::isBlackPiece(pieceId) && !Utils::isBlackKing(pieceId);
	}
	else {
		return Utils::isWhitePiece(pieceId) && !Utils::isWhiteKing(pieceId);
	}
}

bool Piece::isCheck(const Position& pos, Table table) const {
	int pieceId = table[pos.x][pos.y];
	if (Utils::isWhitePiece(this->id) && !Utils::isWhiteKing(this->id)) {
		return Utils::isBlackKing(pieceId);
	}
	if(Utils::isBlackPiece(this->id) && !Utils::isBlackKing(this->id)){
		return Utils::isWhiteKing(pieceId);
	}
	return false;
}
