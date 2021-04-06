#pragma once

#include "Wierzcholek.h"

#include <string>
#include <vector>
#include <iostream>

class Figura {

protected:
    std::string m_name;
    std::vector<Wierzcholek> m_vertices;
public:
    explicit Figura(std::string name);
    Figura& operator+=(const Wierzcholek w);
    Figura& dodajW(const Wierzcholek w);
    std::string nazwa() const;
    virtual int pole() const;
    bool operator== (const Figura& other) const;
    friend std::ostream& operator<< (std::ostream& os, const Figura& f);
};