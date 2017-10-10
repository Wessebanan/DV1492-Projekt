#include "File.h"

File::File(int blockNr, std::string name)
	:FS_item(name)
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
