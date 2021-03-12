#pragma once

#include <iostream>

class Argumenty {

public:
    Argumenty(int count);
    ~Argumenty();
    
    Argumenty& operator() (int index, double value);
    double operator[] (int index) const;
    int count() const;
    void print(const char* text, std::ostream& os = std::cout) const;

private:
    int _count;
    double* _arguments; 

};
