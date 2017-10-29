#pragma once
#include "entity.h"
#include <vector>

class Exit;
class Item;

class Room :
	public Entity
{
public:
	Room(const char* title, const char* description);
	~Room();

	void look() const;

	Exit* getExit(const std::string& direction) const;
	Item* getItem(const std::string& name) const;
	void popItem(const Item* item);
};

