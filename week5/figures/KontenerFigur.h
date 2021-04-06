#pragma once

#include "Figura.h"

class KontenerFigur {

private: 
    std::vector<Figura*> m_container;
public:
    void operator+= (Figura* f);
    friend std::ostream& operator<< (std::ostream& os, const KontenerFigur& k);

};