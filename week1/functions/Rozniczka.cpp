#include "Rozniczka.h"

ProstaRozniczka::ProstaRozniczka(double h) {
    _h = h;
}

Op1* ProstaRozniczka::z(Fun* function) {
    _function = function;
    return this;
}

double ProstaRozniczka::w(const double x) {
    return (_function->wartosc(x + _h) - _function->wartosc(x - _h)) / (2 * _h);
}
