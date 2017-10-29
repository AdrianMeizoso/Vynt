#include "parser.h"
#include "globals.h"
#include <string>

bool existsAction(const std::string action)
{
	const int sizeActions = (sizeof(ACTIONS) / sizeof(*ACTIONS));

	for (int i = 0; i < sizeActions; i++)
	{
		if (Same(action, ACTIONS[i]))
		{
			return true;
		}
	}

	return false;
}
