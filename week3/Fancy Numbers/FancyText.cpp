#include "FancyText.h"

FancyText::FancyText() {
    _string = nullptr;
    _next = nullptr;
    _size = 0;
}

FancyText::FancyText(const char* text) {
    _size = strlen(text);
    _next = nullptr;
    _string = new char[_size + 1];
    strcpy(_string, text);
}

FancyText::FancyText(FancyText&& other) {
    _next = std::__exchange(other._next, nullptr);
    _string = std::__exchange(other._string, nullptr);
    _size = std::__exchange(other._size, 0);
}

FancyText::~FancyText() {
    del();
}

void FancyText::del() {
    if (_string != nullptr) {
        delete[] _string;
        delete _next;
    }
}

void FancyText::operator+= (const char* text) {
    FancyText* next = _next;
    FancyText* current = this;
    while(next != nullptr) {
        current = next;
        next = next->_next;
    }
    current->_next = new FancyText(text);
    _size += strlen(text);
}

void FancyText::operator+= (FancyText* other) {
    if(_next == nullptr) _next = other;
	else *_next += other;
}

void FancyText::operator+=(FancyText&& other) {
	FancyText* text = new FancyText(std::move(other));
	*this += text;
}

void FancyText::operator= (FancyText&& other) {
    del();
    _next = std::__exchange(other._next, nullptr);
    _string = std::__exchange(other._string, nullptr);
    _size = std::__exchange(other._size, 0);
}

int FancyText::size() const {
    return _size;
}

int FancyText::fragments() const {
    int result = 1;
    FancyText* next = _next;
    FancyText* current;
    while(next != nullptr) {
        result++;
        current = next;
        next = next->_next;
    }
    return result;
}

FancyText& FancyText::fragment(int index) const {
    FancyText* next = _next;
    FancyText* current;
    while (index > 0 && next != nullptr) {
        current = next;
        next = next->_next;
    }
    return *current;
}

const char* FancyText::FancyText::str() const {
    return _string;
}

std::ostream& operator<< (std::ostream& os, const FancyText& fancyText) {
    FancyText* next = fancyText._next;
    FancyText* current;
    if (fancyText._string != nullptr) {
            os << fancyText._string;
    }
    while(next != nullptr) {
        current = next;
        os << current->_string << " ";
        next = next->_next;
    }
    return os;
}