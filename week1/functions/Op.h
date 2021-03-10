#pragma once

#include "FElementarne.h"
#include "Trygonometryczne.h"

class Op1 {

public:
    virtual ~Op1() = default;
    virtual Op1* z(Fun* function) {return this;}
    virtual double w(const double x) {return -1.0;}
protected:
    Fun* _function;

};