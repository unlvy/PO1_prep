#pragma once

#include <iostream>

template <typename T1, typename T2> 
struct PairOfNumbers {

	T1& first;
	T2& second;
	PairOfNumbers(T1& type1, T2& type2);
	PairOfNumbers<T2, T1> Swapped();
	void Print() const;
	void Add(T1 value);
	void Scale(T1 value);
	void Info() const;
	void Info();
};

template <typename T1, typename T2> 
PairOfNumbers<T1, T2>::PairOfNumbers(T1& type1, T2& type2) : first(type1), second(type2) {}

template <typename T1, typename T2> 
PairOfNumbers<T2, T1> PairOfNumbers<T1, T2>::Swapped() {
	return PairOfNumbers<T2, T1>(second, first);
}

template <typename T1, typename T2> 
void PairOfNumbers<T1, T2>::Print() const {
	std::cout << "Print method: " << first << " " << second << std::endl;
}

template <typename T1, typename T2> 
void PairOfNumbers<T1, T2>::Add(T1 value) {
	first += value;
	second += static_cast<T1>(value);
}

template <typename T1, typename T2> 
void PairOfNumbers<T1, T2>::Scale(T1 value) {
	first *= value;
	second *= static_cast<T1>(value);
}

template <typename T1, typename T2> 
void PairOfNumbers<T1, T2>::Info() const {

	std::cout << "This is const pair of numbers" << std::endl;
}

template <typename T1, typename T2> 
void PairOfNumbers<T1, T2>::Info() {
	std::cout << "This is NON-const pair of numbers" << std::endl;
}
