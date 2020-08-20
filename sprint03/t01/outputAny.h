#pragma once
#include <iostream>

template<class Container>
void outputAny(const Container& c) {
    for (const auto& item : c) {
        std::cout << item << '\n';
    }
}
