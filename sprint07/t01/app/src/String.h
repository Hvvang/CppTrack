#pragma once

#include "BasicString.h"

namespace CBL {
class String : public CBL::BasicString<char> {
public:
    using BasicString<char>::operator=;
    using BasicString<char>::operator+=;

    String() :
        CBL::BasicString<char>() {}
    String(const CBL::BasicString<char> &str) :
        CBL::BasicString<char>(str) {}
    String(const CBL::BasicString<char> &str, size_t pos, size_t len = npos) :
        CBL::BasicString<char>(str, pos, len) {}
    String(const char *str, size_t n) :
        CBL::BasicString<char>(str, n) {}
    // explicit String(const char *str) :
    //     CBL::BasicString<char>(str) {}
    String(const char * const &str) :
        CBL::BasicString<char>(str) {}
    String(size_t n, char c) :
        CBL::BasicString<char>(n, c) {}
    String(iterator first, iterator last) :
        CBL::BasicString<char>(first, last) {}

    size_t find(const CBL::BasicString<char>& str, size_t pos = 0) const {
        auto lhs_size = this->length();
        auto rhs_size = str.length();

        if (lhs_size < pos) {
            pos = 0;
        }
        for (int i = pos; i < lhs_size; i++) {
            int result = std::char_traits<char>::compare(&(this->at(i)),
                                                         str.c_str(),
                                                         std::min(lhs_size, rhs_size));
            if (result != 0) {
                continue;
            } else {
                return i;
            }
        }
        return npos;
    }
    size_t find(const char* str, size_t pos = 0) const {
        const CBL::BasicString<char> _str(str);
        return find(_str, pos);
    }
    size_t find(char c, size_t pos = 0) const {
        const CBL::BasicString<char> _str(1, c);
        return find(_str, pos);
    }

    size_t rfind(const CBL::BasicString<char>& str, size_t pos = 0) const {
        auto lhs_size = this->length();
        auto rhs_size = str.length();

        if (lhs_size < pos || !pos) {
            pos = lhs_size - 1;
        }
        for (int i = pos; i >= 0; i--) {
            int result = std::char_traits<char>::compare(&(this->at(i)),
                                                         str.c_str(),
                                                         std::min(lhs_size, rhs_size));
            if (result != 0) {
                continue;
            } else {
                return i;
            }
        }
        return npos;
    }
    size_t rfind(const char* str, size_t pos = 0) const {
        const CBL::BasicString<char> _str(str);
        return rfind(_str, pos);
    }
    size_t rfind(char c, size_t pos = 0) const {
        const CBL::BasicString<char> _str(1, c);
        return rfind(_str, pos);
    }
};
}
