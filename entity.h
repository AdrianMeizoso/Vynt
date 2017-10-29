#pragma once
#include <list>

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};


class Entity
{
public:
	Entity(const char* name, const char* description);
	virtual ~Entity();
	virtual void tick();

	std::string name;
	std::string description;

	std::vector<Entity*> container;
};

