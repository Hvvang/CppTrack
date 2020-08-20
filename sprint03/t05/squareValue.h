#pragma once

#include <iterator>
#include <iostream>

template <class Container>
void squareValue(Container& container) {
    std::transform(container.begin(), container.end(), container.begin(),
                   [](auto &value) { return value * value; });
}
