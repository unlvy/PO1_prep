#pragma once

#include "Op.h"

class FZlozona : public Op1 {

public:
    FZlozona(Fun* function);
    Op1* z(Fun* function);
    double w(const double x);
private:
    Fun* _base;
};