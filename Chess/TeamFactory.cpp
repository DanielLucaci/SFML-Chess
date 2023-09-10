#include "TeamFactory.h"

std::vector<Piece*> TeamFactory::createTeam()
{
    addPawns();
    addBishops();
    addQueen();
    addKing();
    addQueen();
    addRooks();
    addKnights();
    return this->_pieces;
}

TeamFactory::TeamFactory(int over): _over(over)
{
}
