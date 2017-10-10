#include "filesystem.h"

FS_item* FileSystem::validFilePath(std::vector<std::string> &filePath) {
	FS_item* toReturn = nullptr;
	Folder* currentSearchDirectory = this->root;
	std::vector<std::string> remainingFilePath = filePath;
	bool valid = true;
	while (valid || toReturn == nullptr) { // As long as the file path is valid and we havent found the end
		std::vector<std::string> currentContent = currentSearchDirectory->getContents(); // Get names of everything in current search directory
		std::string nameToFind = remainingFilePath.front(); // Name at the front of the filepath currently
		bool currentNameFound = false;
		while (currentContent.size() > 0 && !currentNameFound) { // While the current directory still has names to search and the desired name isn't found
			if (currentContent.back() == nameToFind) {
				currentNameFound = true; // Current part of filepath found in directory
			}
			else {
				currentContent.pop_back(); // Remove the recently looked at item, it wasn't what we are looking for
			}
		}
		if (currentNameFound) {
			FS_item* newPointer = currentSearchDirectory->getPointer(nameToFind);
			if (remainingFilePath.size() == 1) { // End of file path, we found what we are looking for, return a pointer to it
				toReturn = newPointer;

			}
			else if (typeid(*newPointer) == typeid(Folder)) {
				currentSearchDirectory == newPointer;
				remainingFilePath.erase(remainingFilePath.begin()); // "pop_front", continue to next part of filepath and do the entire loop again
			}
			else {
				// We are not at the end of the filepath and we found a file or another weird type, this is BAD
				valid = false;
			}
		}
		else { // We searched the entire current searching directory without finding what we are looking for, bad file path
			valid = false;
		}
	}
	return toReturn;
}

std::vector<std::string> FileSystem::parseFilePath(std::string &filePath) {
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
	return stringVec;
}

FileSystem::FileSystem() {
	this->root = new Folder(std::string("root"));
	this->currentDirectory = root;
	this->fullPath = "";
}

FileSystem::~FileSystem() {
	// Här kan behövas mer skit för att rekursivt radera alla pekare i trädet
	delete this->root;
}

void FileSystem::format()
{
	this->mMemblockDevice = MemBlockDevice();
}

bool FileSystem::createFile(std::string & filePath, std::string & fileContent)
{
	return false;
}

bool FileSystem::createFile(std::string &filePath, std::string &fileContent) {
	std::vector<std::string> directoryPath = parseFilePath(filePath);
	std::string fileName = directoryPath.back();
	directoryPath.pop_back(); // The file path entered is the final file path desired for the file, we want to access the directory above it
	FS_item* FSitemPointer = this->validFilePath(directoryPath);
	if (FSitemPointer != nullptr) { // If the file path was valid
		if (typeid(*FSitemPointer) == typeid(Folder)) { // If the file path is a folder and NOT a file
			Folder* directoryPointer = (Folder*)FSitemPointer; // Typecast to folder
			if (directoryPointer->getPointer(fileName) == nullptr) { // If the filename doesnt already exist
				// Everything is set to create the file, do it
				// TODO: ALLOTA SHIZZLITS
			}
		}
	}
	return false;
}

bool FileSystem::createFolder(std::string &filePath) {
	if (validFilePath(this->parseFilePath(filePath)) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFile(std::string &filePath) {
	if (validFilePath(this->parseFilePath(filePath)) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::removeFolder(std::string &filePath) {
	if (validFilePath(this->parseFilePath(filePath)) != nullptr) {
		// Do the thing with the stuff
		return true;
	}
	else
		return false;
}

bool FileSystem::goToFolder(std::string &filePath) {
	FS_item* filePtr = this->validFilePath(this->parseFilePath(filePath));
	bool result = false;
	if (filePtr != nullptr)
	{
		std::string name = typeid(filePtr).name();
		if (name == "Folder")
		{
			this->currentDirectory = dynamic_cast<Folder*>(filePtr);
			result = true;
			this->fullPath = filePath;
		}		
	}
	return result;
}

std::string FileSystem::listDir() {
	std::vector<std::string> stringVec = this->currentDirectory->getContents();
	std::string listString = "";
	while (stringVec.size() > 0)
	{
		listString += stringVec.back() + " ";
		stringVec.pop_back();		
	}
	// Find the folder which is the current directory and print the names of all items inside it
	return listString;
}
bool FileSystem::createImage(std::string filepath)
{
	std::ofstream os;
	os.open(filepath);
	
	return false;
}
bool FileSystem::restoreImage(std::string filepath)
{
	std::ifstream is;
	is.open(filepath);
	
	return false;
}
std::string FileSystem::getFileContents(std::string filepath)
{
	FS_item* filePtr = validFilePath(parseFilePath(filepath));
	std::string contents = "";
	if (filePtr != nullptr)
	{
		std::string name = typeid(filePtr).name();
		if (name == "File")
		{
			File* file = dynamic_cast<File*>(filePtr);
			contents = mMemblockDevice.readBlock(file->getBlockNr()).toString();
		}
	}
	if (contents == "")
	{
		contents = "File does not exist.";
	}	
	return contents;
}
std::string FileSystem::getFullPath()
{
	return this->fullPath;
}
/* Please insert your code */