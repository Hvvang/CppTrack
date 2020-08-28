#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>

template <typename T>
class ClassWithInitializerList final {
public:
    template <typename...Args>
    ClassWithInitializerList(Args&&... args);
    ClassWithInitializerList(const std::initializer_list<T> lst);
    ClassWithInitializerList(const std::vector<T>& vec);
    void outputVector() const;

private:
    std::vector<T> m_vecOfArs;
};

template <typename T>
template <typename...Args>
ClassWithInitializerList<T>::ClassWithInitializerList(Args&&... args) :
    m_vecOfArs{ args... } {}

template <typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::initializer_list<T> lst) :
    m_vecOfArs(lst) {}

template <typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::vector<T>& vec) :
    m_vecOfArs(std::move(vec)) {}

template <typename T>
void ClassWithInitializerList<T>::outputVector() const {
    for (const auto& item : m_vecOfArs) {
        std::cout << item << '\n';
    }
}
