#pragma once

#include "Extended.h"

class Sum : public Extended {

public:
	Sum(Primitive &p1, Primitive &p2) : Extended(p1, p2, '+') {}

	double calc() const override {
		return m_primitive1.calc() + m_primitive2.calc();
	};

	void PrintWithValue() const override {
		print();
		std::cout << " = " << calc() << std::endl;
	}

};