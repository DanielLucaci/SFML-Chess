#include "Knight.h"
#include "TeamManager.h"

Knight::Knight(GameDataRef data, const Position& position, int id) : Piece(data, position, id, PieceType::KNIGHT) {  }

void Knight::Update(Table table) {
    this->Clear();
    Team* team = TeamManager::GetTeam(this->id);
	int d = 0;

    Places dirs = {
        Position(-2, 1), //SSE
        Position(-1, 2), //SE
        Position(1, 2), //NE
        Position(2, 1), //NNE
        Position(2, -1), //NNV
        Position(1, -2), //NV
        Position(-1, -2), //SSV
        Position(-2, -1)
    };

	while (d < 8) {
        Position aux = this->position;
        
        Utils::UpdatePosition(aux, dirs.at(d));
        if (Utils::IsValid(aux) && this->canMakeMove(aux)) {
            // Protect 
            if (this->protect(aux, table))
                team->AddValidPlace(aux);

            // Attack 
            else if (this->attack(aux, table)) 
                this->validMoves.push_back(new CaptureMove(PieceDef(this->id, this->GetPosition(), aux), Utils::getPieceAt(aux, table)));

            // Check
            else if (this->isCheck(aux, table)) 
                this->check = true;

            // Free Square 
            else if (!Utils::getPieceAt(aux, table)) {
                this->validMoves.push_back(new NormalMove(PieceDef(this->id, this->GetPosition(), aux)));
                team->AddValidPlace(aux);
            }
        }
        d++;
	}
    
}