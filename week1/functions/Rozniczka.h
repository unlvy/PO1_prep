#pragma once

#include "Op.h"

class ProstaRozniczka : public Op1 {
    
public:
    ProstaRozniczka(double h);
    Op1* z(Fun* function);
    double w(const double x);
private: 
    double _h;

};