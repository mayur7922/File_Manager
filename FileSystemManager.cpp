#include "FileSystemManager.hpp"
#include "models/Folder.hpp"
#include "models/File.hpp"

FileSystemManager::FileSystemManager(const std::string & rootName) {
    Folder * newRoot = new Folder(rootName);
    this -> root = newRoot;
    folderMapping["root"] = root;
}

Folder * FileSystemManager::getItem(const std:: string name){
    return folderMapping[name];
}

void FileSystemManager::addFolder(const std::string & parentFolderName, const std::string &name){
    Folder * newFolder = new Folder(name);
    Folder * parent = getItem(parentFolderName);
    folderMapping[name] = newFolder;
    parent -> addItem(newFolder);
}
    
void FileSystemManager::addFile(const std::string &parentFolderName, const std::string &name, const std::string & content){
    File * newFile = new File(name,content);
    Folder * parent = getItem(parentFolderName);
    fileMapping[name] = newFile;
    parent -> addItem(newFile);
}

void FileSystemManager::moveFileOrFolder(const std::string &sourceName, const std::string &destinationFolderName, const std::string & filetobeMoved, bool isFolder) {
    Folder * sourceFolder = getItem(sourceName);
    Folder * destinationFolder = getItem(destinationFolderName);
    if(isFolder){
        Folder * folder = folderMapping[filetobeMoved];
        sourceFolder -> removeItem(folder);
        destinationFolder -> addItem(folder);
    }
    else{
        File * file = fileMapping[filetobeMoved];
        sourceFolder -> removeItem(file);
        destinationFolder -> addItem(file);
    }
}

std::vector<std::string> FileSystemManager::listContents(const std::string & folderName) {
    Folder * folder = folderMapping[folderName];
    vector<FileSystemItem *> v = folder -> getItems();
    vector<std::string> items;
    for(FileSystemItem * i : v){
        items.push_back(i -> getName());
    }
    return items;
}

std::string FileSystemManager::searchFileExactMatch(const std::string &folderName, const std::string &fileName) {
    Folder * folder = folderMapping[folderName];
    vector<FileSystemItem *> v = folder -> getItems();
    for(FileSystemItem * i : v){
        if(i -> getName() == fileName) return i -> getName();
    }
    return "";
}

std::vector<std::string> FileSystemManager::searchFileLikeMatch(const std::string &folderName, const std::string &pattern) {
    Folder * folder = folderMapping[folderName];
    vector<FileSystemItem *> v = folder -> getItems();
    vector<std::string> items;
    for(FileSystemItem * i : v){
        string str = i -> getName();
        if(str.find(pattern) != std::string::npos) {
            items.push_back(str);
        }
    }
    return items;
}