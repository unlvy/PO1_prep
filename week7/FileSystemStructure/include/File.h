#pragma once

#include "FileSystemBase.h"

class File : public FileSystemBase {

public:
    explicit File(std::string name);
};
