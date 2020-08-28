#pragma once

#include <iostream>
// #include <stdexcept>

/* SomeClass.h */
class SomeClass {
public:
    SomeClass() = default;
    SomeClass(int intVal, char charVal, float floatVal) :
        m_intArg(intVal), m_charArg(charVal), m_floatArg(floatVal) {}

    void output() const {
        std::cout << "SomeClass: ";
        std::cout << m_intArg << " " << m_charArg << " " << m_floatArg;
    }

private:
    int m_intArg;
    char m_charArg;
    float m_floatArg;
};
