#include "Argumenty.h"
    
Argumenty::Argumenty(int size) : _size(size) {
    if (_size > 0) {
        _array = new double[_size];
    }
}

Argumenty::Argumenty(const Argumenty& other) : _size(other._size) {
    if (_size > 0) {
        _array = new double[_size];
    }
    for (int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

Argumenty::~Argumenty() {
    if (_array != nullptr) {
        delete[] _array;
    }
}

int Argumenty::getSize() const {
    return _size;
}

Argumenty& Argumenty::operator() (int index, double value) {
    if (index >= 0 && index < _size) {
        _array[index] = value;
    } 
    return *this;
}

Argumenty& Argumenty::operator= (const Argumenty& other) {
    if (_array != nullptr) {
        delete[] _array;
    }
    _size = other._size;
    if (_size > 0) {
        _array = new double[_size];
    }
    for (int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
    return *this;
}

double Argumenty::operator[] (int index) const {
    return _array[index];
}

Argumenty Argumenty::pojedynczy(double value) {
    Argumenty result(1);
    result(0, value);
    return result;
}

std::ostream& operator<< (std::ostream& os, const Argumenty& a) {
    for (int i = 0; i < a._size; i++) {
        os << a._array[i] << " ";
    }
    return os;
}