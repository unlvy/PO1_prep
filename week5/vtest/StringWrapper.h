#pragma once

#include "Wrapper.h"

class StringWrapper : public Wrapper {

private:
    char* m_string;
    int m_size;
public:
    explicit StringWrapper(const char* string);
    ~StringWrapper() override;
    const char* toString() const override;
};