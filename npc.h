#pragma once
#include "creature.h"
class Npc : public Creature
{
public:
	Npc(const char* title, const char* description, Room* room);
	~Npc();
};

