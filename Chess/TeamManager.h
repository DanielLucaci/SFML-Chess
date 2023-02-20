#pragma once
#include "Team.h"
#include "Utils.h"

class TeamManager
{
public: 
	TeamManager() = default;
	static void LoadTeams(Team* white, Team* black) {
		_whiteTeam = white;
		_blackTeam = black;
	}

	static Team* GetTeam(int id) {
		return Utils::isWhitePiece(id) ? _whiteTeam : _blackTeam;
	}

	static Team* GetOppositeTeam(int id) {
		return Utils::isWhitePiece(id) ? _blackTeam : _whiteTeam;
	}

	static void AddMove(Move* move) {
		if (_blackTeam->GetMoves().size() < _whiteTeam->GetMoves().size())
			_blackTeam->AddMove(move);
		else 
			_whiteTeam->AddMove(move);
	}

	static Move* GetLastMove() {
		if (_whiteTeam->GetMoves().size() > _blackTeam->GetMoves().size()) 
			return _whiteTeam->GetLastMove();
		return _blackTeam->GetLastMove();
		
	}


	static Team* _whiteTeam;
	static Team* _blackTeam;
	static Moves _moves; 
};

