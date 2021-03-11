#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) {
	_real = real;
	_imaginary = imaginary;
}

ComplexNumber::operator double() const {
    return _real;
}

ComplexNumber& ComplexNumber::operator= (const ComplexNumber& other) {
    if(&other != this) {
        _real = other._real;
        _imaginary = other._imaginary;
    }
    return *this;
}

void ComplexNumber::operator*= (int multipler) {
    _real *=  multipler;
    _imaginary *= multipler;
}

ComplexNumber& ComplexNumber::operator++() {
    _real += 1;
    return *this;
}

ComplexNumber ComplexNumber::operator++(int) {
    ComplexNumber result(this->_real, this->_imaginary);
    ++(*this);
    return result;
}

double& ComplexNumber::operator[] (unsigned index) {
    if (index == 0) {
        return _real;
    } else {
        return _imaginary;
    }
}


std::ostream& operator<< (std::ostream& os, const ComplexNumber& complexNumber) {
    if (complexNumber._real != 0) {
        os << complexNumber._real;
    }
    if (complexNumber._imaginary > 0) {
        os << " + " << complexNumber._imaginary << "i";
    } else  if (complexNumber._imaginary < 0) {
        os << " - " << complexNumber._imaginary * (-1.0) << "i";
    }
    return os;
}

ComplexNumber operator+ (const ComplexNumber& cn1, const ComplexNumber& cn2) {
    return ComplexNumber(cn1._real + cn2._real, cn1._imaginary + cn2._imaginary);
}

ComplexNumber operator+ (int value, const ComplexNumber& complexNumber) {
    return ComplexNumber((double)value + complexNumber._real, complexNumber._imaginary);
}

ComplexNumber operator* (const ComplexNumber& cn1, const ComplexNumber& cn2) {
    return ComplexNumber(cn1._real * cn2._real - cn1._imaginary * cn2._imaginary,
                         cn1._real * cn2._imaginary + cn1._imaginary * cn2._real);
}

ComplexNumber operator- (const ComplexNumber& cn1, const ComplexNumber& cn2) {
    return ComplexNumber(cn1._real - cn2._real, cn1._imaginary - cn2._imaginary);
}