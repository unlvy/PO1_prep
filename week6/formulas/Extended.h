#pragma once

#include "Primitive.h"

class Extended : public Primitive {

protected:
	Primitive& m_primitive1;
	Primitive& m_primitive2;
	char m_char;

public:

	Extended(Primitive &p1, Primitive &p2, char c = '\0') : Primitive(0), m_primitive1(p1), m_primitive2(p2), m_char(c) {}

	void print() const override {
		std::cout << "(";
		m_primitive1.print();
		std::cout << m_char;
		m_primitive2.print();
		std::cout << ")";
	}

	virtual void PrintWithValue() const = 0;
};