#include "Figura.h"

Figura::Figura(std::string name) : m_name(name) {
    std::cout << "Jestem nowa figura " << m_name << std::endl;
}

Figura& Figura::operator+=(const Wierzcholek w) {
    m_vertices.push_back(w);
    return *this;
}

Figura& Figura::dodajW(const Wierzcholek w) {
    return *this+=w;
}

std::string Figura::nazwa() const {
    return m_name;
}

int Figura::pole() const {
    return -1;
}

bool Figura::operator== (const Figura& other) const {
    
    if (this == &other) {
        return true;
    } else if (m_vertices.size() != other.m_vertices.size()) {
        return false;
    } else {
        for (int i = 0; i < static_cast<int>(m_vertices.size()); i++) {
            if (m_vertices[i] != other.m_vertices[i]) {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<< (std::ostream& os, const Figura& f) {
    os << "figura " << f.nazwa() << ":" << std::endl;;
    for (int i = 0; i < static_cast<int>(f.m_vertices.size()); i++) {
        os << f.m_vertices[i];
    }
    return os << std::endl;
}