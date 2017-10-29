#include "item.h"
#include <iostream>
#include <string>

Item::Item(const char * title, const char * description) :
	Entity(title, description)
{
	type = ITEM;
}

Item::~Item()
{
}

void Item::look() const
{
	std::cout << name << "\n";
	std::cout << description << "\n";
}

void Item::lookDeeper() const
{

}
