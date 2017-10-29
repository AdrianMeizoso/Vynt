#pragma once
#include "entity.h"

class Room;

class Exit :
	public Entity
{
public:
	Exit(const char* title, const char* description, Room* destination);
	~Exit();

	Room* destination;
};

