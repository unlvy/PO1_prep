#include "StringWrapper.h"

StringWrapper::StringWrapper(const char* string) : m_size(strlen(string) + 1) {
    m_string = new char[m_size];
    strcpy(m_string, string);
}

StringWrapper::~StringWrapper() {
    if (m_string != nullptr) {
        delete[] m_string;
    }
}

const char* StringWrapper::toString() const {
    char* result = new char[m_size];
    strcpy(result, m_string);
    return result;
}