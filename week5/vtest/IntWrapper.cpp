#include "IntWrapper.h"

IntWrapper::IntWrapper(int value) : m_value(value) {}

const char* IntWrapper::toString() const {
    char* result = new char[30];
    sprintf(result, "%d", m_value);
    return result;
}