#include "SekwencjaAlgorytmow.h"

void SekwencjaAlgorytmow::add(const std::function<Argumenty(const Argumenty&)> alg) {
    _algorithms.push_back(alg);
}

Argumenty SekwencjaAlgorytmow::procesuj(const Argumenty& a) const {
    Argumenty result(a);
    for (int i = 0; i < (int)_algorithms.size(); i++) {
        result = _algorithms[i](result);
    }
    return result;
}
