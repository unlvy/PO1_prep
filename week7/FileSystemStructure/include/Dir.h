#pragma once

#include "FileSystemBase.h"

class Dir : public FileSystemBase {

public:
    explicit Dir(std::string name);
    Dir* findDir(std::string name) const;
    void add(Dir* dir);
};
