#include "FloatWrapper.h"

FloatWrapper::FloatWrapper(float value) : m_value(value) {}

const char* FloatWrapper::toString() const {
    char* result = new char[30];
    sprintf(result, "%.1f", m_value);
    return result;
}