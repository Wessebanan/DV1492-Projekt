#ifndef FOLDER_H
#define FOLDER_H

#include "File.h"
#include <vector>
#define INCREMENT 10
class Folder : public FS_item
{
private:
	FS_item** items;
	int nItems;
	int size;
	void expand();

public:
	Folder(std::string name, std::string path);
	~Folder();

	void addFile(int blockNr, std::string name);
	void addFolder(std::string name);

	void removeFile(int blockNr);
	void removeFolder();

	std::vector<std::string> getContents();
	FS_item* getPointer(std::string name);
	int getNitems();

	std::vector<std::string> getAllContents();

};
#endif