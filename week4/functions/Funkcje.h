#pragma once

#include <iostream>
#include <cmath>

class Sinus {
    private:
        double m_a;
        double m_b;
    public:
        Sinus(double a, double b);
        double operator() (double x) const;
};

class PierwiastekKwadratowy {
public:
    double operator() (double x) const;
};

class Liniowa {
    private:
        double m_a;
        double m_b;
    public:
        Liniowa(double a, double b);
        double operator() (double x) const;
};
