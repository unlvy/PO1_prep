#pragma once

#include <iostream>
#include <cmath>

class Wierzcholek {

private: 
    int m_x;
    int m_y;
public:
    Wierzcholek(int x, int y);
    double dist(const Wierzcholek& other) const;
    friend std::ostream& operator<< (std::ostream& os, const Wierzcholek& w);
    bool operator!= (const Wierzcholek& other) const;
};