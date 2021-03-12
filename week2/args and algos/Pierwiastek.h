#pragma once

#include "Suma.h"

#include <cmath>

class Pierwiastek : public Algo {

public:

    Pierwiastek* sklonuj() {
        return new Pierwiastek();
    }

    Argumenty wykonaj(const Argumenty& a) const {
        int count = a.count();
        Argumenty result(count);
        for (int i = 0; i < count; i++) {
            result(i, sqrt(a[i]));
        }
        return result;
    }
};
