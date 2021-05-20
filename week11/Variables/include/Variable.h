#pragma once

#include <string>
#include <iostream>

class Wrapper {
protected:
	std::string m_name;
public:
	explicit Wrapper(std::string name) : m_name(name) {}
	virtual ~Wrapper() = default;
	virtual void Print() const = 0;
};


template<typename T>
class Variable : public Wrapper {
protected:
	T m_value;
public:
	Variable(std::string name, T value) : Wrapper(name), m_value(value) {}
	virtual void Print() const override { std::cout << m_name << ": " << m_value << std::endl; }
	virtual void SetValue(T value) { m_value = value; }
};

template<typename T>
class VariableWithUnits : public Variable<T> {
private:
	std::string m_unit;
public:
	VariableWithUnits(std::string name, T value, std::string unit) : Variable<T>(name, value), m_unit(unit) {}
	void Print() const override { std::cout << Variable<T>::m_name << ": " << Variable<T>::m_value << " [" << m_unit << "]" << std::endl; }
};

class ArrayOfVariables {
private:
	Wrapper** m_array;
	unsigned m_index;
	unsigned m_size;
public:
	explicit ArrayOfVariables(unsigned size) : m_array(new Wrapper*[size]), m_index(0), m_size(size) {
		for (unsigned i = 0; i < m_size; i++) {
			m_array[i] = nullptr;
		}
	}

	~ArrayOfVariables() { 
		for (unsigned i = 0; i < m_size; i++) {
			if (m_array[i] != nullptr) {
				delete m_array[i];
			}
		}
		delete[] m_array;
	}

	template<typename T> Variable<T>* CreateAndAdd(std::string name, T value) {
		Variable<T>* result = new Variable(name, value);
		m_array[m_index++] = result;
		return result;
	}

	void Print() const {
		for(unsigned i = 0; i < m_size; i++) {
			if (m_array[i] != nullptr) {
				m_array[i]->Print();
			}
		}
	}


};

using VariableDouble = Variable<double>;
using VariableFloat = Variable<float>;
using VariableInt = Variable<int>;
using VariableChar = Variable<char>;
using VariableBool = Variable<bool>;
