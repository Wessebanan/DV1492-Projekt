#ifndef FILE_H
#define FILE_H
#include<string>
#include "FS_item.h"
class File : public FS_item
{
private:
	int blockNr;

public:
	File(int blockNr, std::string name, std::string path);
	~File();

	int getBlockNr();
};

#endif