#pragma once

#include "BasicString.h"

namespace CBL {
class WString : public CBL::BasicString<wchar_t> {
public:
    using BasicString<wchar_t>::operator=;
    using BasicString<wchar_t>::operator+=;

    WString() :
        CBL::BasicString<wchar_t>() {}
    WString(const CBL::BasicString<wchar_t> &str) :
        CBL::BasicString<wchar_t>(str) {}
    WString(const CBL::BasicString<wchar_t> &str, size_t pos, size_t len = npos) :
        CBL::BasicString<wchar_t>(str, pos, len) {}
    WString(const wchar_t *str, size_t n) :
        CBL::BasicString<wchar_t>(str, n) {}
    // explicit WString(const wchar_t *str) :
    //     CBL::BasicString<wchar_t>(str) {}
    WString(const wchar_t * const &str) :
        CBL::BasicString<wchar_t>(str) {}
    WString(size_t n, wchar_t c) :
        CBL::BasicString<wchar_t>(n, c) {}
    WString(iterator first, iterator last) :
        CBL::BasicString<wchar_t>(first, last) {}

    size_t find(const CBL::BasicString<wchar_t>& str, size_t pos = 0) const {
        auto lhs_size = this->length();
        auto rhs_size = str.length();

        if (lhs_size < pos) {
            pos = 0;
        }
        for (int i = pos; i < lhs_size; i++) {
            int result = std::char_traits<wchar_t>::compare(&(this->at(i)), str.c_str(), std::min(lhs_size, rhs_size));
            if (result != 0) {
                continue;
            } else {
                return i;
            }
        }
        return npos;
    }
    size_t find(const wchar_t* str, size_t pos = 0) const {
        const CBL::BasicString<wchar_t> _str(str);
        return find(_str, pos);
    }
    size_t find(wchar_t c, size_t pos = 0) const {
        const CBL::BasicString<wchar_t> _str(1, c);
        return find(_str, pos);
    }

    size_t rfind(const CBL::BasicString<wchar_t>& str, size_t pos = 0) const {
        auto lhs_size = this->length();
        auto rhs_size = str.length();

        if (lhs_size < pos || !pos) {
            pos = lhs_size - 1;
        }
        for (int i = pos; i >= 0; i--) {
            int result = std::char_traits<wchar_t>::compare(&(this->at(i)), str.c_str(), std::min(lhs_size, rhs_size));
            if (result != 0) {
                continue;
            } else {
                return i;
            }
        }
        return npos;
    }
    size_t rfind(const wchar_t* str, size_t pos = 0) const {
        const CBL::BasicString<wchar_t> _str(str);
        return rfind(_str, pos);
    }
    size_t rfind(wchar_t c, size_t pos = 0) const {
        const CBL::BasicString<wchar_t> _str(1, c);
        return rfind(_str, pos);
    }
};
}
