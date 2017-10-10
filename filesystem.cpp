#include "filesystem.h"

bool FileSystem::validFilePath(std::string &filePath) {
	// Check if the filepath is an actual file or folder
}

FileSystem::FileSystem() {

}

FileSystem::~FileSystem() {

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

/* Please insert your code */