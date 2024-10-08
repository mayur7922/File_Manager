#include <string>

class FileSystemItem {
protected:
    std::string name;

public:
    FileSystemItem(const std::string &name);

    std::string getName() const;

    virtual bool isFolder() const = 0;
};