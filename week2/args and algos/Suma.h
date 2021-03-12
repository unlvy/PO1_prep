#pragma once

#include "Argumenty.h"
#include <iostream>

class Algo {

public:
    virtual Argumenty wykonaj(const Argumenty& a) const = 0;
    virtual Algo* sklonuj() = 0;
    virtual ~Algo() = default;
protected:
private:

};

class Suma : public Algo {

public:

    Suma* sklonuj() {
        return new Suma();
    }

    Argumenty wykonaj(const Argumenty& a) const {
        double sum = 0.0;
        int count = a.count();
        for(int i = 0; i < count; i++) {
            sum += a[i];
        }
        Argumenty result(1);
        result(0, sum);
        return result;
    }
};