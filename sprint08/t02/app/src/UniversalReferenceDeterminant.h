#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>
#include <typeinfo>
#include <type_traits>

/* UniversalReferenceDeterminant.h */
namespace UniversalReferenceDeterminant {

template <typename T>
void determineReference(T&& obj) {
    std::cout << typeid(decltype(obj)).name() << " is ";
    if (std::is_rvalue_reference<decltype(obj)>::value)
        std::cout << "r-value reference\n";
    else {
        std::cout << "l-value reference\n";
    }
}
} // end namespace UniversalReferenceDeterminan
