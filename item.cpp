#include "item.h"

Item::Item(const char * title, const char * description) :
	Entity(title, description)
{
	type = ITEM;
}

Item::~Item()
{
}
