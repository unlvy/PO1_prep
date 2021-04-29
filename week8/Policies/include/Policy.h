#pragma once

#include <string>

struct Policy {
	std::string policyName() const { return _name; } // zwraca nazwę używanej polityki
protected:
	std::string _name; 
};

struct CachePolicy : public Policy {
    virtual void cacheValueForArgument( double arg, double val ) = 0; // zapamietuje warosc obliczenia dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;  // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual double getCached(double arg) const = 0; // zapamietana wartosc dla argumentu
protected:
	double lastArg;
	double lastVal;
};

struct VerbosityPolicy : public Policy {
    virtual void printArgAndResult( double arg, double val) const = 0; // wypisuje na stdout argument i wynik dzialania na tym argumencie
};