#pragma once

#include "Argumenty.h"

#include <vector>
#include <functional>

struct SekwencjaAlgorytmow {

    void add(const std::function<Argumenty(const Argumenty&)> alg);
    Argumenty procesuj(const Argumenty& a) const;

private:
    std::vector<std::function<Argumenty(const Argumenty&)>> _algorithms;

};
