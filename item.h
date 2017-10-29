#pragma once
#include "entity.h"
class Item :
	public Entity
{
public:
	Item(const char* title, const char* description);
	~Item();

	void look() const;
	void lookDeeper() const;
};

