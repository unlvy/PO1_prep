#include "FElementarne.h"

Fun* Liniowa::utworz() {
    return new Liniowa;
}

double Liniowa::wartosc(double x) const {
    return _a * x + _b;
}



Fun* Kwadratowa::utworz() {
    return new Kwadratowa;
}

double Kwadratowa::wartosc(double x) const {
    return _a * x * x + _b * x + _c;
}
