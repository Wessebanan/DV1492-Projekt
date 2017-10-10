#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "Folder.h"
#include "memblockdevice.h"
#include <fstream>
#include <vector>

class FileSystem
{
private:
    MemBlockDevice mMemblockDevice;
	Folder* currentDirectory;
	Folder* root;

	std::string fullPath;

	FS_item* validFilePath(std::vector<std::string> &filePath);
	std::vector<std::string> parseFilePath(std::string &filePath);
    // Here you can add your own data structures
public:
    FileSystem();
    ~FileSystem();

    /* These API functions need to be implemented
	   You are free to specify parameter lists and return values
    */
	void format();

    /* This function creates a file in the filesystem */
	bool createFile(std::string &filePath, std::string &fileContent);

    /* Creates a folder in the filesystem */
    bool createFolder(std::string &filePath);

    /* Removes a file in the filesystem */
    bool removeFile(std::string &filePath);

    /* Removes a folder in the filesystem */
    bool removeFolder(std::string &filePath);

    /* Function will move the current location to a specified location in the filesystem */
    bool goToFolder(std::string &filePath);

    /* This function will get all the files and folders in the specified folder */
	// Kommer typ alltid vara current directory eftersom ls är kommandot
	std::string listDir();

	bool createImage(std::string filepath);
	bool restoreImage(std::string filepath);
	std::string getFileContents(std::string filepath);//cat
	std::string getFullPath();
    /* Add your own member-functions if needed */
};

#endif // FILESYSTEM_H
