#include "creature.h"
#include "entity.h"


Creature::Creature(const char * name, const char * description, Room* room) :
	Entity(name, description), room(room)
{

}

Creature::~Creature()
{
}
