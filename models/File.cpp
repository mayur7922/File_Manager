#include "File.hpp"

File::File(const std::string& name, const std::string & content) : FileSystemItem(name) {
    this -> content = content;
}

bool File :: isFolder() const {
    return false;
}