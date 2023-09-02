#include "King.h"
#include "TeamManager.h"

King::King(const Position& position, int id) : Piece(position, id, PieceType::KING) {}

bool King::isValidKing(const Position& position, Table table, const Places& places) {
	// Outside the table 
	if (!Utils::IsValid(position)) 
		return false;
	return !Utils::isPlaceProtected(position, places); // check if the square is not protected by the other team
}

void King::Update(Table table) {
	// Clear piece data
	this->Clear();

	Team* team = TeamManager::GetTeam(this->id);
	Team* oppositeTeam = TeamManager::GetOppositeTeam(this->id);
	Places protectedPlaces = TeamManager::GetOppositeTeam(this->id)->GetValidPlaces();

	int d = 0;
	Places dirs{
		Position(-1, -1), // NV
		Position(1, 1), // SE
		Position(-1, 1), // SV
		Position(1, -1), // NE
		Position(-1, 0), // V
		Position(1, 0), // E
		Position(0, -1), // N
		Position(0, 1) // S
	};
	

	while (d < 8) {
		Position pos = this->position;
		Utils::UpdatePosition(pos, dirs.at(d));
		if (this->isValidKing(pos, table, protectedPlaces)) {
			// Attack
			if (this->attack(pos, table))
				this->validMoves.push_back(new CaptureMove(PieceDef(this->id, this->GetPosition(), pos), Utils::getPieceAt(pos, table)));

			// Protect
			else if (this->protect(pos, table))
				team->AddValidPlace(pos);
			
			// Free square
			else {
				bool ok = true;
				// Check if it's team 
				if(oppositeTeam->isCheck()) {
					const Pieces& givingCheckPieces = oppositeTeam->getGivingCheckPiece();
					for (Piece* p : givingCheckPieces) {
						Position pos2 = p->GetPosition();
						switch (p->GetPieceType()) {
							case PieceType::BISHOP:
							case PieceType::QUEEN:
							case PieceType::ROOK:
								if (Utils::IsBetween(pos2, pos, this->position))
									ok = false;
								break;
							default:
								break;
						}
					}
					// Get the piece giving check 
				}

				if (ok) {
					this->validMoves.push_back(new NormalMove(PieceDef(this->id, this->GetPosition(), pos)));
					team->AddValidPlace(pos);
				}
			}
		}
		d++;
	}
}