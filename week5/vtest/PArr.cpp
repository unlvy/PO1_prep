#include "PArr.h"

PArr::PArr(int size) : m_size(size) {
    m_array = new Wrapper* [size];
    for(int i = 0; i < size; i++) {
        m_array[i] = nullptr;
    }	
}

PArr::PArr(const PArr& other) {
    m_size = other.m_size;
    m_array = new Wrapper*[other.m_size];
    for (int i = 0; i < m_size; i++) {
        m_array[i] = other.m_array[i];
    }
}

PArr::PArr(PArr&& other) {
    m_size = std::__exchange(other.m_size, 0);
    m_array = std::move(other.m_array);
}

PArr::~PArr() {
    if (m_array != nullptr) {
        for (int i = 0; i < m_size; i++) {
            delete m_array[i];
        }
        delete[] m_array;
    }
}

PArr& PArr::operator= (const PArr& other) {
    if (this != &other) {
        if (m_array != nullptr) {
            for (int i = 0; i < m_size; i++) {
                delete m_array[i];
            }
            delete[] m_array;
        }
        m_size = other.m_size;
        m_array = new Wrapper*[m_size];
        for (int i = 0; i < m_size; i++) {
            m_array[i] = other.m_array[i];
        }
    }
    return *this;
}

Wrapper*& PArr::operator[] (int index) {
    return m_array[index];
}

std::ostream& operator<< (std::ostream& os, const PArr& parr) {
    for (int i = 0; i < parr.m_size; i++) {
        if (parr.m_array[i] == nullptr) {
            os << "nothing" << " ";
        } else {
            const char* temp = parr.m_array[i]->toString();
            os << temp << " ";
            delete[] temp;
        }
    }
    os << std::endl;
    return os;
}