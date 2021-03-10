#include "FZlozona.h"

FZlozona::FZlozona(Fun* function) {
    _base = function;
}

Op1* FZlozona::z(Fun* function) {
    _function = function;
    return this;
}

double FZlozona::w(const double x) {
   return _base->wartosc(_function->wartosc(x));
}