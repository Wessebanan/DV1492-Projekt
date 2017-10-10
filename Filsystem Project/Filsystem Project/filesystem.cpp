#include "filesystem.h"

bool FileSystem::validFilePath(std::string &filePath) {
	bool result = false;
	// Check if the filepath is an actual file or folder
	return result;
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
	if (validFilePath(filePath)) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::createFolder(std::string &filePath) {
	if (validFilePath(filePath)) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFile(std::string &filePath) {
	if (validFilePath(filePath)) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFolder(std::string &filePath) {
	if (validFilePath(filePath)) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::goToFolder(std::string &filePath) {
	if (validFilePath(filePath)) {
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