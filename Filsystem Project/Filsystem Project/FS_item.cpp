#include "FS_item.h"

FS_item::FS_item(std::string name, std::string path)
{
	this->name = name;
	this->path = path;
	this->path += this->name + '/';
	if (this->name == "root")
	{
		this->path = "";
	}
}

FS_item::~FS_item()
{
}

std::string FS_item::getName()
{
	return this->name;
}

std::string FS_item::getPath()
{
	return this->path;
}
