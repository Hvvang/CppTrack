#pragma once

#include <iostream>
#include <iterator>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<int> out_it (std::cout, "\n");
    std::copy(container.begin(), container.end(), out_it);
}
