#include "Queen.h"
#include "TeamManager.h"
#include "PieceManager.h"

Queen::Queen(const Position& position, int id) : Piece(position, id, PieceType::QUEEN) {  }

void Queen::Update(Table table) {
    this->Clear();
    Team* team = TeamManager::GetTeam(this->id);
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
        sf::Vector2i aux = this->position;
        bool ok = true;
        while (ok) {
            Utils::UpdatePosition(aux, dirs.at(d));

            if (Utils::IsValid(aux) && this->canMakeMove(aux)) {
                int currentPos = Utils::getPieceAt(aux, table);

                // Protect 
                if (this->protect(aux, table)) {
                    team->AddValidPlace(aux);
                    ok = false;
                }

                // Attack 
                else if (this->attack(aux, table)) {
                    this->validMoves.push_back(
                        new CaptureMove(
                            PieceDef(this->id, this->GetPosition(), aux),
                            currentPos
                        )
                    );
                    ok = false;

                    Utils::UpdatePosition(aux, dirs.at(d));

                    while (Utils::IsValid(aux)) {
                        if (this->isCheck(aux, table)) {
                            Piece* p = PieceManager::GetPieceMap().at(currentPos);
                            p->SetLockingPiece(this);
                            this->SetLockedPiece(p);
                            break;
                        }
                        else if (this->protect(aux, table) || this->attack(aux, table)) {
                            break;
                        }
                        Utils::UpdatePosition(aux, dirs.at(d));
                    }
                }

                // Check
                else if (this->isCheck(aux, table)) {
                    this->check = true;
                    ok = false;
                }

                // King 
                else if (Utils::isKing(currentPos))
                    ok = false;

                // Free Square
                else {
                    this->validMoves.push_back(new NormalMove(PieceDef(this->id, this->GetPosition(), aux)));
                    team->AddValidPlace(aux);
                }
            }
            else {
                ok = false;
            }
        }
        d++;
    }
}
