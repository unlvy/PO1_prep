#pragma once

#include <iostream>
#include <cmath>

class V {

public:
    explicit V(int dimensions);
    V(const V& other);
    ~V();

    int& at(unsigned index) const;
    void print(const char* text) const;
    static double dot(const V& v1, const V& v2);
    double norm() const;
    operator double() const;
    static V sum(const V& v1, const V& v2);
    static V sum(const V& v, int value);


private:
    int _dimensions;
    int* _vector;

};