#include "Pawn.h"
#include "TeamManager.h"

Pawn::Pawn(const Position& position, int id) : Piece(position, id, PieceType::PAWN) {  }

void Pawn::Update(Table table) {
    this->Clear();
    Team* team = TeamManager::GetTeam(this->id);

    Position pos = this->position;
    // White pawns
    Position pos1(pos.x + 1, pos.y); // front 
    Position pos2(pos.x + 1, pos.y - 1); // attack left 
    Position pos3(pos.x + 1, pos.y + 1); // attack right
    Position pos4(pos.x + 2, pos.y); // Pawn can jump over one square at the beginning

    if (this->id > 8) { // Black pawns
        pos1.x = pos2.x = pos3.x = pos.x - 1;
        pos4.x = pos.x - 2;
    }

    // Two squares
    if (!this->moved &&
        Utils::isFreeSpace(pos4, table) &&
        Utils::isFreeSpace(pos1, table) &&
        this->canMakeMove(pos4)) 
    {
        this->validMoves.push_back(new NormalMove(PieceDef(this->id, this->GetPosition(), pos4)));
    }
    
    // One square      
    if (Utils::isFreeSpace(pos1, table) && this->canMakeMove(pos1)) {
        if (pos1.x == 0 || pos1.x == 7)
            this->validMoves.push_back(new TransformMove(PieceDef(this->id, this->GetPosition(), pos4)));
        else 
            this->validMoves.push_back(new NormalMove(PieceDef(this->id, this->GetPosition(), pos1)));
    }
        
   
    // Left attack
    if (Utils::IsValid(pos2)) {
        if (this->attack(pos2, table) && this->canMakeMove(pos2)) {
            if (pos2.x == 0 || pos2.x == 7)
                this->validMoves.push_back(new TransformMove(PieceDef(this->id, this->GetPosition(), pos2)));
            else 
                this->validMoves.push_back(new CaptureMove(PieceDef(this->id, this->GetPosition(), pos2), Utils::getPieceAt(pos2, table)));
        }

        else if (this->isCheck(pos2, table))
            this->SetCheck(true);

        else
            team->AddValidPlace(pos2);
    }

    // Right attack
    if (Utils::IsValid(pos3)) { 
        if (this->attack(pos3, table) && this->canMakeMove(pos3)) {
            if (pos3.x == 0 || pos3.x == 7)
                this->validMoves.push_back(new TransformMove(PieceDef(this->id, this->GetPosition(), pos3)));
            else 
                this->validMoves.push_back(new CaptureMove(PieceDef(this->id, this->GetPosition(), pos3), Utils::getPieceAt(pos3, table)));
        }

        else if (this->isCheck(pos3, table))
            this->SetCheck(true);

        else
            team->AddValidPlace(pos3);
    }
}
