#ifndef FOLDER_H
#define FOLDER_H

#include "File.h"
#define INCREMENT 10
class Folder : public FS_item
{
private:
	FS_item** items;
	int nItems;
	int size;
	void expand();

public:
	Folder(std::string name);
	~Folder();

	void addFile(int blockNr);
	void addFolder(std::string name);

};
#endif