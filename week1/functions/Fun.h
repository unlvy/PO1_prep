#pragma once

#include <iostream>
#include <cmath>

class Fun {

public:
    virtual ~Fun() = default;
    virtual double wartosc(double x) const {return 0.0;}
    Fun* a(double a) {
        _a = a;
        return this;
    }
    Fun* b(double b) {
        _b = b;
        return this;
    }
    Fun* c(double c) {
        _c = c;
        return this;
    }
protected:
    double _a;
    double _b;
    double _c;

};