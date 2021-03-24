#pragma once

#include "Argumenty.h"

#include <cmath>

Argumenty minimum(const Argumenty& arg) {
    double min = arg[0];
    for (int i = 1; i < arg.getSize(); i++) {
        if (arg[i] < min) {
            min = arg[i];
        }
    }   
    return Argumenty(1)(0, min);
}

Argumenty sum(const Argumenty& arg) {
    double sum = arg[0];
    for (int i = 1; i < arg.getSize(); i++) {
        sum += arg[i];
    }   
    return Argumenty(1)(0, sum);
}

Argumenty sq(const Argumenty& arg) {
    return Argumenty(1)(0, sqrt(arg[0]));
}
