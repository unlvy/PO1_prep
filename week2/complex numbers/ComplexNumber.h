#pragma once

#include <iostream>

class ComplexNumber {

public:
	explicit ComplexNumber(double real, double imaginary = 0.0);
    ~ComplexNumber() = default;

    operator double() const;
    ComplexNumber& operator= (const ComplexNumber& other);
    void operator*= (int multipler);
    ComplexNumber& operator++();
    ComplexNumber operator++(int);
    double& operator[] (unsigned index);

    friend std::ostream& operator<< (std::ostream& os, const ComplexNumber& complexNumber);
    friend ComplexNumber operator+ (const ComplexNumber& cn1, const ComplexNumber& cn2);
    friend ComplexNumber operator+ (int value, const ComplexNumber& complexNumber);
    friend ComplexNumber operator* (const ComplexNumber& cn1, const ComplexNumber& cn2);
    friend ComplexNumber operator- (const ComplexNumber& cn1, const ComplexNumber& cn2);


private:
	double _real;
	double _imaginary;



};