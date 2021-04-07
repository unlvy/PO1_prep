#pragma once

#include "Wrapper.h"

class IntWrapper : public Wrapper {

private:
    int m_value;
public:
    explicit IntWrapper(int value);
    const char* toString() const override;
};