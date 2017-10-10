#include "Folder.h"

Folder::Folder(std::string name)
	:FS_item(name)
{
	this->nItems = 0;
	this->size = 10;
	this->items = new FS_item*[this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->items[i] = nullptr;
	}
}

Folder::~Folder()
{
	for (int i = 0; i < this->nItems; i++)
	{
		if (this->items[i] != nullptr)
		{
			delete this->items[i];
		}
	}
	delete[] this->items;
}

void Folder::expand()
{
	FS_item** temp = new FS_item*[this->size + INCREMENT];
	for (int i = 0; i < this->nItems; i++)
	{
		temp[i] = this->items[i];
	}
	this->size += INCREMENT;
	for (int i = this->nItems; i < this->size; i++)
	{
		temp[i] = nullptr;
	}
	delete[] this->items;
	this->items = temp;

}

void Folder::addFile(int blockNr, std::string name)
{
	if (this->nItems == this->size)
	{
		this->expand();
	}
	this->items[this->nItems++] = new File(blockNr, name);

	
}

void Folder::addFolder(std::string name)
{
	if (this->nItems == this->size)
	{
		this->expand();
	}
	this->items[this->nItems++] = new Folder(name);
}

void Folder::removeFile(int blockNr)
{
	File* filePtr = nullptr;
	for (int i = 0; i < this->nItems; i++)
	{
		filePtr = nullptr;
		filePtr = dynamic_cast<File*>(items[i]);
		if ((filePtr != nullptr) && (blockNr == filePtr->getBlockNr()))
		{
			delete items[i];
			items[i] = nullptr;
		}
	}
	this->nItems--;
}

void Folder::removeFolder()
{
	if (this->nItems == 0)
	{
		delete this;
	}
}

std::vector<std::string> Folder::getContents()
{
	std::vector<std::string> contents;
	for (int i = 0; i < this->nItems; i++)
	{
		contents.push_back(this->items[i]->getName());
	}
	return contents;
}

FS_item * Folder::getPointer(std::string name)
{
	FS_item* ptr = nullptr;

	for (int i = 0; (i < this->nItems) && (ptr == nullptr); i++)
	{
		if (name == this->items[i]->getName())
		{
			ptr = this->items[i];
		}
	}
	return ptr;
}
