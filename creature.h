#pragma once
#include "entity.h"
#include "room.h"

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

public:
	Room* room;

};

