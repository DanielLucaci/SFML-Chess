#include "BoxManager.h"
#include "InvalidMoveBox.h"
#include "InvalidPieceBox.h"
#include "BlackWinsBox.h"
#include "WhiteWinsBox.h"
#include "CheckmateBox.h"
#include "StalemateBox.h"
#include "TransformBox.h"

BoxManager::BoxManager(GameDataRef data): _data(data) {
	this->LoadBoxes();
}

void BoxManager::LoadBoxes()
{
	this->_boxes["Black Wins"] = new BlackWinsBox(this->_data);
	this->_boxes["White Wins"] = new WhiteWinsBox(this->_data);
	this->_boxes["Checkmate"] = new CheckmateBox(this->_data);
	this->_boxes["Stalemate"] = new StalemateBox(this->_data);
	this->_boxes["Invalid Move"] = new InvalidMoveBox(this->_data);
	this->_boxes["Invalid Piece"] = new InvalidPieceBox(this->_data);
	this->_boxes["Transform Piece"] = new TransformBox(this->_data);
}

MessageBox* BoxManager::GetBox(const std::string& name) const {
	return this->_boxes.at(name);
}