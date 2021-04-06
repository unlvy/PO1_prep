#include "Wierzcholek.h"

Wierzcholek::Wierzcholek(int x, int y) : m_x(x), m_y(y) {}

std::ostream& operator<< (std::ostream& os, const Wierzcholek& w) {
    os << "(" << w.m_x << ", " << w.m_y << ") ";
    return os;
}

double Wierzcholek::dist(const Wierzcholek& other) const {
    return sqrt( pow( m_x - other.m_x, 2 ) + pow( m_y - other.m_y, 2 ));
}

bool Wierzcholek::operator!= (const Wierzcholek& other) const {
    if (m_x == other.m_x && m_y == other.m_y) {
        return false;
    } else {
        return true;
    }
}