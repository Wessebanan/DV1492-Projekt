#include "FS_item.h"

FS_item::FS_item(std::string name)
{
	this->name = name;
}

FS_item::~FS_item()
{
}

std::string FS_item::getName()
{
	return this->name;
}
