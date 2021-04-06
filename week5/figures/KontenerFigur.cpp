#include "KontenerFigur.h"

void KontenerFigur::operator+= (Figura* f) {
    m_container.push_back(f);
}

std::ostream& operator<< (std::ostream& os, const KontenerFigur& k) {
    for (int i = 0; i < static_cast<int>(k.m_container.size()); i++) {
        os << *k.m_container[i];  
    } 
    return os;
}