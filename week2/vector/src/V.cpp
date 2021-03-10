#include "../include/V.h"

V::V(int dimensions) {
    _dimensions = dimensions;
    _vector = new int[_dimensions];
    for (int i = 0; i < _dimensions; i++) {
        _vector[i] = 0;
    }
}

V::V(const V& other) {
    _dimensions = other._dimensions;
    _vector = new int[_dimensions];
    for (int i = 0; i < _dimensions; i++) {
        _vector[i] = other._vector[i];
    }
}

V::~V() {
    delete[] _vector;
}

int& V::at(unsigned index) const {
   return _vector[index];
}

void V::print(const char* text) const {
    std::cout << text << "= (";
    if(_dimensions > 0) {
        std::cout << _vector[0];
        for (int i = 1; i < _dimensions; i++) {
            std::cout << ", " << _vector[i];
        }
    }
    std::cout << ")" << std::endl;
}

double V::dot(const V& v1, const V& v2) {
    if (v1._dimensions != v2._dimensions) {
        std::cout << "Error, vectors of different dimensions!" << std::endl;
        return 0.0;
    } else {
        double result = 0.0;
        for (int i = 0; i < v1._dimensions; i++) {
            result += v1._vector[i] * v2._vector[i];
        }
        return result;
    }
}

double V::norm() const {
    double result = 0.0;
    for (int i = 0; i < _dimensions; i++) {
        result += pow(_vector[i], 2);
    }
    return sqrt(result);
}

V::operator double() const {
    return norm();
}

V V::sum(const V& v1, const V& v2) {
    int size = std::max(v1._dimensions, v2._dimensions);
    V result(size);
    for (int i = 0; i < size; i++) {
        result.at(i) = v1.at(i) + v2.at(i);
    }
    return result;
}

V V::sum(const V& v, int value) {
    V result(v._dimensions);
    for (int i = 0; i < v._dimensions; i++) {
        result.at(i) = v.at(i) + value;
    }
    return result;
}