#pragma once

#include <iostream>

class Primitive {
private:

	double m_value;

public:

	explicit Primitive(double value) : m_value(value) {}

	virtual ~Primitive() = default;

	void Set(double value) { 
		m_value = value; 
	}

	virtual void print() const { 
		std::cout << m_value; 
	}

	virtual double calc() const { 
		return m_value; 
	}

};