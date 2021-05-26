#pragma once

#include "PairOfNumbers.h"

template <typename T1, typename T2 = int>
class RangeArray {
private:
	unsigned m_size;
	T1* m_array;
public:
	explicit RangeArray(PairOfNumbers<T2, T1> pair);
	RangeArray(const RangeArray& other);
	~RangeArray();
	unsigned Size() const;
	T1& operator[](int index);
	T1 At(int index) const;
};

template <typename T1, typename T2>
RangeArray<T1, T2>::RangeArray(PairOfNumbers<T2, T1> pair) {
	m_size = pair.second - pair.first;
	m_array = new T1[m_size];
}

template <typename T1, typename T2>
RangeArray<T1, T2>::RangeArray(const RangeArray& other) {
	m_size = other.m_size;
	m_array = new T1[m_size];
	for (unsigned i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}

template <typename T1, typename T2>
RangeArray<T1, T2>::~RangeArray() {
	delete m_array;
}

template <typename T1, typename T2>
unsigned RangeArray<T1, T2>::Size() const {
	return m_size;
}

template <typename T1, typename T2>
T1& RangeArray<T1, T2>::operator[](int index) {
	index = index < 0 ? m_size + index : index;
	return m_array[index];
}

template <typename T1, typename T2>
T1 RangeArray<T1, T2>::At(int index) const {
	index = index < 0 ? m_size + index : index;
	return m_array[index];
}
