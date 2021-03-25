#include "ZlozenieFunkcji.h"

void ZlozenieFunkcji::insert(std::function<double(double)> function) {
    m_functions.emplace_back(function);
}

double ZlozenieFunkcji::wynik(double x) {
    m_results.clear();
    double result = x;
    for (int i = 0; i < (int)m_functions.size(); i++) {
        result = m_functions[i](result);
        m_results.push_back(result);
    }
    return result;
}

double ZlozenieFunkcji::operator[] (int index) {
    return m_results[index];
}
