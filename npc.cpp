#include "npc.h"


Npc::Npc(const char * title, const char * description, Room* room) :
	Creature(title, description, room)
{
	type = CREATURE;
}

Npc::~Npc()
{
}
