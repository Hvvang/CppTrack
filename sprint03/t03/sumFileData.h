#pragma once

#include <iterator>
#include <fstream>


template <class T>
T sumFileData(const std::string& fileName) {
    std::istream_iterator<T> eos;
    std::ifstream file(fileName);
    std::istream_iterator<T> iit(file);
    T value = 0;

    while (iit != eos) {
        value += *iit;
        iit++;
    }
    file.close();
    return value;
}
