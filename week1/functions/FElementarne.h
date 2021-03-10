#pragma once

#include "Fun.h"

class Liniowa : public Fun {

public: 
    static Fun* utworz();
    double wartosc(double x) const;

private: 
    explicit Liniowa() = default;
};

class Kwadratowa : public Fun {

public: 
    static Fun* utworz();
    double wartosc(double x) const;

private: 
    explicit Kwadratowa() = default;
};