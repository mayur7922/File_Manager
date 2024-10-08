#include<iostream>
#include <string>
using namespace std;

#include "FileSystemItem.hpp"

class File : public FileSystemItem {
public:

    string content;

    File(const std::string & name, const std::string & content);

    bool isFolder() const override;
    
};