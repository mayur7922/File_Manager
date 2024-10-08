#include <iostream>
#include <map>
#include "models/FileSystemItem.hpp"
#include "models/Folder.hpp"
#include "models/File.hpp"

class FileSystemManager {
private:
    Folder * root;
    map<string, Folder *> folderMapping;
    map<string, File *> fileMapping;
public:
    FileSystemManager(const std::string & rootName);

    Folder * getItem(const std:: string name);

    void addFolder(const std::string &parentFolderName, const std::string &name);

    void addFile(const std::string &parentFolderName, const std::string &name, const std::string & content);

    void moveFileOrFolder(const std::string &sourceName, const std::string &destinationFolderName, const std::string & filetobeMoved, bool isFolder);

    std::vector<std::string> listContents(const std::string &folderName);

    std::string searchFileExactMatch(const std::string &folderName, const std::string &fileName);

    std::vector<std::string> searchFileLikeMatch(const std::string &folderName, const std::string &pattern);
};