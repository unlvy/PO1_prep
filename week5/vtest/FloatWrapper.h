#pragma once

#include "Wrapper.h"

class FloatWrapper : public Wrapper {

private:
    float m_value;
public:
    explicit FloatWrapper(float value);
    const char* toString() const override;
};