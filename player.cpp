#include "player.h"
#include "exit.h"
#include "globals.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>

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
	
	if (args.size() == 2)
	{

		if (Same(args[1], "me"))
		{
			std::cout << "\n" << name << "\n";
			std::cout << description << "\n";
		}
		else
		{
			std::cout << "I only understood you as far as wanting to \"" << args[0] << "\"\n";
		}
	}
	else
	{
		room->look();
	}
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

void Player::examine(const std::vector<std::string>& args)
{
	if (args.size() == 2) {
		for (std::vector<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]) && (*it)->type == ITEM)
			{
				Item *item = (Item*)*it;
				item->look();
				return;
			}
		}
	}
	else
	{
		std::cout << "I only understood you as far as wanting to \"" << args[0] << "\"\n";
	}
}

void Player::inventory() const
{
	if (container.size() == 0)
	{
		std::cout << "You are empty handed.\n";
		return;
	}
	else
	{
		for (std::vector<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
		{
			std::cout << (*it)->name << "\n";
		}
	}
}

void Player::take(const std::vector<std::string>& args)
{
	if (args.size() == 2)
	{
		Item* item = (Item*)room->getItem(args[1]);

		if (item == nullptr)
		{
			std::cout << "There is no item here like this.\n";
		}
		else
		{
			std::cout << item->name << " taken.\n";
			container.push_back(item);
			room->popItem(item);
		}
	}
}

void Player::drop(const std::vector<std::string>& args)
{
	if (args.size() == 2)
	{
		for (std::vector<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]) && (*it)->type == ITEM)
			{
				Item* ex = (Item*)*it;
				container.erase(it);
			}
		}
	}
}
