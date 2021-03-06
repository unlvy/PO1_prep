#pragma once

#include <iostream>
#include <cmath>

class Fraction {

public:

    /// constructors
    explicit Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& other);
    Fraction(Fraction&& other);

    /// destructor
    ~Fraction() = default;

    /// other methods

    /// operators overloaded as methods
    void operator+= (const int value);
    Fraction& operator= (const Fraction& other);
    operator double() const;
    int operator[] (const int index) const;

    /// friend functions
    friend bool operator> (const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend Fraction& operator- (Fraction& fraction);
    friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
    friend Fraction operator* (const Fraction& f1, const Fraction& f2);
    friend Fraction operator* (const int multipler, const Fraction& fraction);
    friend std::ostream& operator<< (std::ostream& stream, const Fraction& fraction);

    /// auxiliary function
    friend void simplify(Fraction& fraction);


    private:
        int _numerator;
        int _denominator;

};