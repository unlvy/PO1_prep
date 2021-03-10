#pragma once

#include "Fun.h"

class Sinus : public Fun {

public: 
    explicit Sinus() = default;
    static Fun* utworz();
    double wartosc(double x) const;

private: 
    
};