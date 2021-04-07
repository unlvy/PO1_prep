#pragma once

#include <cstring>
#include <iostream>

class Wrapper {

public:
    virtual ~Wrapper() {};
    virtual const char* toString() const = 0;
};