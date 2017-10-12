#ifndef FS_ITEM_H
#define FS_ITEM_H
#include <vector>
#include <string>

class FS_item
{
protected:
	std::string name;
	std::string path;
public:
	FS_item(std::string name, std::string path);
	virtual ~FS_item();
	std::string getName();
	std::string getPath();

};

#endif