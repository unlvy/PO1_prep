#pragma once

#include "Wrapper.h"

class PArr {

private:
    Wrapper** m_array;
    int m_size;
public:
    explicit PArr(int size);
    PArr(const PArr& other);
    PArr(PArr&& other);
    ~PArr();
    PArr& operator= (const PArr& other);
    Wrapper*& operator[] (int index);
    friend std::ostream& operator<< (std::ostream& os, const PArr& parr);
};