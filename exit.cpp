#include "exit.h"


Exit::Exit(const char * title, const char * description, Room* destination) :
	Entity(title, description), destination(destination)
{
	type = EXIT;
}

Exit::~Exit()
{
}
