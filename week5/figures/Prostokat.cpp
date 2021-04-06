#include "Prostokat.h"

Prostokat::Prostokat(std::string name) : Figura(name) {
    std::cout << "Tak naprawde jestem prostokatem" << std::endl;
} 

int Prostokat::pole() const {
    return static_cast<int>(abs(m_vertices[0].dist(m_vertices[1]) * m_vertices[0].dist(m_vertices[3])));
}