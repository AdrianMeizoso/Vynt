#pragma once
#include "entity.h"
#include <vector>

class Room :
	public Entity
{
public:
	Room(const char* title, const char* description);
	~Room();

	void look(const std::vector<std::string>& args) const;

	Exit* getExit(const std::string& direction) const;
};

