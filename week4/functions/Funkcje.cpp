#include "Funkcje.h"

Sinus::Sinus(double a, double b) : m_a(a), m_b(b) {}

double Sinus::operator() (double x) const {
    return sin(m_a * x + m_b);
}

double PierwiastekKwadratowy::operator() (double x) const {
    return sqrt(x);
}

Liniowa::Liniowa(double a, double b) : m_a(a), m_b(b) {}

double Liniowa::operator() (double x) const {
    return m_a * x + m_b;
}
