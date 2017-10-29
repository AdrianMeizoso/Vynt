#pragma once
#include <vector>

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

	EntityType type;
	std::string name;
	std::string description;

	std::vector<Entity*> container;
};

