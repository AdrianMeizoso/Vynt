#include <iostream>
#include "world.h"
#include "globals.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"



World::World()
{
	Room* forest = new Room("Forest", "You are surrounded by tall trees. It feels like a huge forest someone could get lost easily.");
	Room* house = new Room("House", "You are inside a beautiful but small white house.");

	Exit* ex1 = new Exit("west", "Little path", house);
	forest->container.push_back(ex1);

	Item* mailbox = new Item("Mailbox", "It seems an ordinary object.");
	house->container.push_back(mailbox);

	Item* key = new Item("Key", "Old iron key.");
	mailbox->container.push_back(key);


	player = new Player("Adri", "El tope power", forest);
}


World::~World()
{
	
}

void World::tick()
{
}

void World::executeCommand(std::vector<std::string>& args)
{
	if (Same(args[0], "look") || Same(args[0], "l"))
	{
		player->look(args);
	}
	else if (Same(args[0], "go"))
	{
		player->go(args);
	}
	else if (Same(args[0], "examine"))
	{
		player->examine(args);
	}
	else if (Same(args[0], "inventory") || Same(args[0], "i"))
	{
		player->inventory();
	}
	else if (Same(args[0], "take"))
	{
		player->take(args);
	}
	else if (Same(args[0], "drop"))
	{
		player->drop(args);
	}
	else
	{
		std::cout << "I do not recognize that action\n";
	}
}
