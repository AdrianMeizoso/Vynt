#pragma once
#include "entity.h"
class Exit :
	public Entity
{
public:
	Exit(const char* title, const char* description);
	~Exit();
};

