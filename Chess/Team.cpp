#include "Team.h"
#include <iterator>
#include <exception>

Team::Team(Table table) {
	this->check = this->doubleCheck = false;
	this->over = -1;
	this->_table = table;
	for (int i = 0; i < 8; i++)
		this->_table[i] = table[i];
}

Team::Team(const Team& other) {
	this->check = other.check;
	this->givingCheck = other.givingCheck;
	this->doubleCheck = other.doubleCheck;
	this->_validPlaces = other._validPlaces;
	this->pieces = other.pieces;
	this->over = other.over;
	this->_table = other._table;
	for (int i = 0; i < 8; i++)
		this->_table[i] = other._table[i];
}

Team::~Team()
{

}

Team& Team::operator=(const Team& team) {
	if (this == &team) {
		return *this;
	}
	this->check = team.check;
	this->doubleCheck = team.doubleCheck;
	this->_validPlaces = team._validPlaces;
	this->pieces = team.pieces;
	this->_table = team._table;
	for (int i = 0; i < 8; i++)
		this->_table[i] = team._table[i];
	return *this;
}

const Pieces& Team::getGivingCheckPiece() const
{
	return this->givingCheck;
}

const Pieces& Team::getPieces() const
{
	return this->pieces;
}


const bool& Team::isCheck() const {
	return this->check;
}

const bool& Team::isDoubleCheck() const
{
	return this->doubleCheck;
}

Move* Team::GetLastMove() 
{
	return this->_moves.top();
}

void Team::AddMove(Move* move)
{
	this->_moves.push(move);
}

int Team::GetOver() const
{
	return this->over;
}

void Team::IncrementOver()
{
	this->over++;
}

const Moves& Team::GetMoves() const
{
	return this->_moves;
}

const Places& Team::GetValidPlaces() const
{
	return this->_validPlaces;
}

void Team::Clear()
{
	this->_validPlaces.clear();
	this->givingCheck.clear();
}

bool Team::hasValidMoves() const
{
	for (Piece* p : this->pieces)
		if (!p->GetCaptured() && p->GetValidMoves().size() != 0)
			return true;
	return false;
}

void Team::displayValidPlaces() const {
	std::cout << '\n';
	for (Piece* p : this->pieces)
		for (Move* m : p->GetValidMoves())
			std::cout << p->GetId() << " " << m->GetActualPosition().x << " " << m->GetActualPosition().y << '\n';
}


void Team::Update(Team* other) {
	// Clear all the team data
	this->Clear();
	this->check = false;

	// Iterate over all pieces
	for (Piece* p : this->pieces) {
		if (p->GetPieceType() == PieceType::KING)
			continue;		

		if (p->GetCaptured() == true)
			continue;

		int id = p->GetId();

		p->Update(this->_table);

		if (p->GetPieceType() == PieceType::PAWN)
			this->checkForEnPassant(id);
	
		// Update check state
		if (p->GetCheck()) {
			this->givingCheck.push_back(p);
			if (this->check == true) {
				this->doubleCheck = true;
			}
			else {
				this->check = true;
			}
		}
	}
}


void Team::AddValidPlace(const Position& pos)
{
	if (std::find(this->_validPlaces.begin(), this->_validPlaces.end(), pos) == this->_validPlaces.end()) 
		this->_validPlaces.push_back(pos);
}



