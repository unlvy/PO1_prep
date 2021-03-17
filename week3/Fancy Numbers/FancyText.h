#pragma once

#include <iostream>
#include <string.h>

class FancyText {

public:
    FancyText();
    FancyText(const char* text);
    FancyText(FancyText&& other);
    ~FancyText();
    void del();


    void operator+= (const char* text);
    void operator+= (FancyText* other);
    void operator+= (FancyText&& other);

    void operator= (FancyText&& other);

    int size() const;
    int fragments() const;
    FancyText& fragment(int index) const;
    const char* str() const;

    friend std::ostream& operator<< (std::ostream& os, const FancyText& fancyText);

private:
    char* _string;
    int _size;
    FancyText* _next;    
};