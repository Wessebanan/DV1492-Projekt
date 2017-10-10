#ifndef FS_ITEM_H
#define FS_ITEM_H

#include <string>

class FS_item
{
protected:
	std::string name;

public:
	FS_item(std::string name);
	virtual ~FS_item();
	std::string getName();

};

#endif