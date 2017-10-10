#include "filesystem.h"

FS_item* FileSystem::validFilePath(std::vector<std::string> &filePath) {
	FS_item* toReturn = nullptr;
	Folder* currentSearchDirectory = this->root;
	bool valid = true;
	while (valid || toReturn == nullptr) {
		//std::vector<std::string> currentContent = currentSearchDirecory.getContents();
	}
	return toReturn;
}

std::vector<std::string> parseFilePath(std::string &filePath) {
	// Reads a filepath of format "dir/dir/dir/file" and outputs a vector with each string
	std::string currentName;
	std::vector<std::string> stringVec;
	for (int i = 0; i < filePath.size(); i++) {
		if (filePath[i] != '\\' && filePath[i] != '/')
			currentName = currentName + filePath[i];
		else {
			stringVec.push_back(currentName);
			currentName.clear();
		}
	}
}

FileSystem::FileSystem() {
	this->root = new Folder(std::string("root"));
	this->currentDirectory = root;
}

FileSystem::~FileSystem() {
	// Här kan behövas mer skit för att rekursivt radera alla pekare i trädet
	delete this->root;
}

bool FileSystem::createFile(std::string &filePath) {
	if (validFilePath(filePath) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::createFolder(std::string &filePath) {
	if (validFilePath(filePath) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFile(std::string &filePath) {
	if (validFilePath(filePath) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFolder(std::string &filePath) {
	if (validFilePath(filePath) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::goToFolder(std::string &filePath) {
	if (validFilePath(filePath) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

std::string FileSystem::listDir() {
	std::string listString;
	// Find the folder which is the current directory and print the names of all items inside it
	return listString;
}
/* Please insert your code */