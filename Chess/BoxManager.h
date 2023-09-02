#pragma once
#include <map>
#include "MessageBox.h"

typedef std::map<std::string, MessageBox*> BoxMap;

class BoxManager
{
public:
	BoxManager();
	MessageBox* GetBox(const std::string&) const;
private:
	void LoadBoxes();
	BoxMap _boxes;
};

