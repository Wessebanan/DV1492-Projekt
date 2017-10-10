#ifndef FILE_H
#define FILE_H

#include "FS_item.h"
class File : public FS_item
{
private:
	int blockNr;

public:
	File(int blockNr, std::string name);
	~File();

	int getBlockNr();
};

#endif