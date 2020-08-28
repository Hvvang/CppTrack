#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
/* Serializer.h */
class Serializer {
public:
    template <class T>
    void serialize(const T* object, const std::string& fileName) {
        if (std::ofstream file(fileName, std::ios_base::binary); file) {
            file.write(reinterpret_cast<const char *>(object), sizeof(T));
        } else {
            throw std::invalid_argument("error");
        }
    }

    template <class T>
    T deserialize(const std::string& fileName) {
        if (std::ifstream file(fileName, std::ios_base::binary); file) {
            T object;
            file.read(reinterpret_cast<char *>(&object), sizeof(T));
            return object;
        } else {
            throw std::invalid_argument("error");
        }
    }
};
