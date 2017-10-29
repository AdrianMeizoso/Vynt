#include <iostream>
#include "world.h"
#include "globals.h"
#include "room.h"
#include "player.h"
#include "exit.h"



World::World()
{
	Room* forest = new Room("Forest", "You are surrounded by tall trees. It feels like a huge forest someone could get lost easily.");
	Room* house = new Room("House", "You are inside a beautiful but small white house.");

	Exit* ex1 = new Exit("west", "Little path", house);
	forest->container.push_back(ex1);

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
	if (Same(args[0], "go"))
	{
		player->go(args);

	}
	else
	{
		std::cout << "I do not recognize that action\n";
	}

	//	std::cout << "I only understood you as far as wanting to \"" << args[0] << "\"\n";

}
