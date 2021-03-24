#pragma once

#include <iostream>

class Argumenty {

private: 
    double* _array = nullptr;
    int _size = 0;

public: 

    explicit Argumenty(int size);
    Argumenty(const Argumenty& other);

    ~Argumenty();

    int getSize() const;

    Argumenty& operator() (int index, double value);
    Argumenty& operator= (const Argumenty& other);

    double operator[] (int index) const;

    static Argumenty pojedynczy(double value); 

    friend std::ostream& operator<< (std::ostream& os, const Argumenty& a);

};
