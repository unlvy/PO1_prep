#include "fraction.h"

/// constructors
Fraction::Fraction() {
    Fraction(0, 1);
}

Fraction::Fraction(int numerator) {
    _numerator = numerator;
    _denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if(denominator == 0) {
        std::cout << "ERROR! Denominator cant be equal to 0!" << std::endl;
        Fraction(0, 1);
    } else {
        _numerator = numerator;
        _denominator = denominator;
        simplify(*this);
    }
}

Fraction::Fraction(const Fraction& other) {
    _numerator = other._numerator;
    _denominator = other._denominator;
}

Fraction::Fraction(Fraction&& other) {
    _numerator = std::__exchange(other._numerator, 0);
    _denominator = std::__exchange(other._denominator, 1);
}

/// other methods
/// operators overloaded as methods

void Fraction::operator+= (const int value) {
    _numerator += value * _denominator;
    simplify(*this);
}

Fraction& Fraction::operator= (const Fraction& other) {
    if (other == *this) {
        return *this;
    } else {
        _numerator = other._numerator;
        _denominator = other._denominator;
        return *this;
    }
}

Fraction::operator double() const {
    return (double)_numerator/_denominator;
}

int Fraction::operator[] (const int index) const {
    if (index < 0) {
        std::cout << "Wrong index!" << std::endl;
        return INT8_MIN;
    } else if (index == 0) {
        return _numerator;
    } else {
        return _denominator;
    }
}

/// friend functions

bool operator> (const Fraction& f1, const Fraction& f2) {
    return (double)f1._numerator/f1._denominator > (double)f2._numerator/f2._denominator;
}

bool operator< (const Fraction& f1, const Fraction& f2) {
    return (double)f1._numerator/f1._denominator < (double)f2._numerator/f2._denominator;
}

Fraction& operator- (Fraction& fraction) {
    fraction._numerator *= -1;
    return fraction;
}

Fraction operator+ (const Fraction& f1, const Fraction& f2) {
    return Fraction(f1._numerator * f2._denominator + f1._denominator * f2._numerator, 
                    f1._denominator * f2._denominator);
}

Fraction operator* (const Fraction& f1, const Fraction& f2) {
    return Fraction(f1._numerator * f2._numerator, f1._denominator * f2._denominator);
}

Fraction operator* (const int multipler, const Fraction& fraction) {
    return Fraction(fraction._numerator * multipler, fraction._denominator);
}

std::ostream& operator<< (std::ostream& stream, const Fraction& fraction) {
    if (fraction._denominator == 1) {
        stream << fraction._numerator;
    } else {
        stream << fraction._numerator << "/" << fraction._denominator;
    }
    return stream;
}

/// auxiliary functions

int gcd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
}

void simplify(Fraction& fraction) {
    int greatestCommonDivisor;
    while((greatestCommonDivisor = gcd(fraction._numerator, fraction._denominator)) > 1) {
        fraction._numerator /= greatestCommonDivisor;
        fraction._denominator /= greatestCommonDivisor;
    }

    if(fraction._denominator < 0) {
        fraction._numerator *= -1;
        fraction._denominator *= -1;        
    }

}
