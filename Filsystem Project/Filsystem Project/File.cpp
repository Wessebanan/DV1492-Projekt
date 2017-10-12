#include "File.h"

File::File(int blockNr, std::string name, std::string path)
	:FS_item(name, path)
{
	this->blockNr = blockNr;
}

File::~File()
{
}

int File::getBlockNr()
{
	return this->blockNr;
}
