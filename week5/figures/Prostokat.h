#pragma once
#include "Figura.h"

#include <cmath>

class Prostokat : public Figura {

public:
    explicit Prostokat(std::string name);
    int pole() const override;
};
