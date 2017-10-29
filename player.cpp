#include "player.h"
#include "exit.h"
#include <iostream>
#include <list>
#include <string>

Player::Player(const char * title, const char * description, Room* room) :
	Creature(title,	description, room)
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::look(const std::vector<std::string>& args) const
{
	room->look();

	/*
	if (args.size() > 1)
	{
		for (std::list<Entity*>::const_iterator it = parent->container.begin(); it != parent->container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]) || ((*it)->type == EXIT && Same(args[1], ((Exit*)(*it))->GetNameFrom((Room*)parent))))
			{
				(*it)->Look();
				return;
			}
		}

		if (Same(args[1], "me"))
		{
			cout << "\n" << name << "\n";
			cout << description << "\n";
		}
	}
	else
	{
		parent->Look();
	}
	*/
}

void Player::go(const std::vector<std::string>& args)
{
	if (args.size() == 2) {
		Exit* exit = room->getExit(args[1]);

		if (exit == nullptr)
		{
			std::cout << "There is no exit at '" << args[1] << "'.\n";
		}
		else
		{
			room = exit->destination;
			room->look();
		}
	}
	else
	{
		std::cout << "I only understood you as far as wanting to \"" << args[0] << "\"\n";
	}
}
