#include "Argumenty.h"

Argumenty::Argumenty(int count) {
    _count = count;
    if (_count > 0) {
    _arguments = new double[_count];
    } else {
        _arguments = nullptr;
    }
}

Argumenty::~Argumenty() {
    if(_arguments != nullptr) {
        delete[] _arguments;
    }
}

Argumenty& Argumenty::operator() (int index, double value) {
    _arguments[index] = value;
    return *this;
}

double Argumenty::operator[] (int index) const {
    return _arguments[index];
}

int Argumenty::count() const {
    return _count;
}

void Argumenty::print(const char* text, std::ostream& os) const {
    os << text;
    for(int i = 0; i < _count; i++) {
        os << " " <<  _arguments[i];
    }
    os << std::endl;
}