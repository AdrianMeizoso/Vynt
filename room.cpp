#include "room.h"
#include "entity.h"
#include <iostream>
#include <string>


Room::Room(const char * title, const char * description) :
	Entity(title, description)
{

}

Room::~Room()
{
}

void Room::look(const std::vector<std::string>& args) const
{
	std::cout << name << "\n";
	std::cout << description << "\n";
}

Exit* Room::getExit(const std::string & direction) const
{
	for (std::vector<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* ex = (Exit*)*it;
			if (Same(ex->GetNameFrom(this), direction))
				return ex;
		}
	}

	return nullptr;
}
