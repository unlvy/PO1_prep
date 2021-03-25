#pragma once

#include <iostream>
#include <functional>
#include <vector>

class ZlozenieFunkcji {

private:
    std::vector<std::function<double(double)>> m_functions;
    std::vector<double> m_results;
public:
    void insert(std::function<double(double)> function);
    double wynik(double x);
    double operator[] (int index);
};
