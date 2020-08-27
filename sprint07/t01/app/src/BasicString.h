#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>

namespace CBL {

template <class T>
class BasicString {
public:
    using iterator= T*;
    static const size_t npos = -1ul;

    BasicString() {}
    BasicString(const BasicString<T> &str) : BasicString(str.begin(), str.end()) {}
    BasicString(const BasicString<T> &str, size_t pos, size_t len = npos)  {
        m_size = len != npos ? std::min(str.m_size - pos, len) : str.m_size - pos;
        m_buffer = new T[m_size + 1];
        std::copy(str.m_buffer + pos, str.m_buffer + pos + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    explicit BasicString(const T *str) {
        m_size = std::char_traits<T>::length(str);
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(const T *str, size_t n) {
        m_size = std::min(std::char_traits<T>::length(str), n);
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(size_t n, T c) {
        m_size = n;
        m_buffer = new T[m_size + 1];
        std::fill(m_buffer, (m_buffer + n), c);
        m_buffer[n] = '\0';
    }
    BasicString(iterator first, iterator last) {
        m_size = last - first;
        m_buffer = new T[m_size + 1];
        std::copy(first, last, this->begin());
        m_buffer[m_size] = '\0';
    }
    virtual ~BasicString() {
        delete[] m_buffer;
        m_size = 0;
    }

    // iterators
    iterator begin() const {
        return m_buffer;
    }
    iterator end() const {
        return m_buffer + m_size;
    }

    // capacity
    size_t length() const {
        return m_size;
    }

    // element access
    T& operator[](size_t index) const {
        return m_buffer[index];
    }
    T& at(size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("basic_string");
        } else {
            return m_buffer[index];
        }
    }
    T& back() const {
        return (*this)[m_size - 1];
    }
    T& front() const {
        return (*this)[0];
    }

    // modifiers
    BasicString<T> &operator=(const BasicString<T> &str) {
        delete[] m_buffer;
        m_size = str.m_size;
        m_buffer = new T[m_size + 1];
        std::copy(str.begin(), str.end(), m_buffer);
        m_buffer[m_size] = '\0';
        return *this;
    }
    BasicString<T> &operator=(const T *str) {
        return operator=(BasicString<T>{str});
    }
    BasicString<T> &operator=(const T c) {
        return operator=(BasicString<T>{1, c});
    }

    BasicString<T>& operator+=(const BasicString<T>& str) {
        append(str);
        return *this;
    }
    BasicString<T>& operator+=(const T* str)  {
        append(str);
        return *this;
    }
    BasicString<T>& operator+=(const T c)  {
        append(1, c);
        return *this;
    }

    void append(const BasicString<T>& str) {
        T *p = new T[m_size + str.m_size + 1];
        std::copy(begin(), end(), p);
        std::copy(str.begin(), str.end(), p + m_size);
        m_size += str.m_size;
        delete[] m_buffer;
        p[m_size] = '\0';
        m_buffer = p;
    }
    void append(const T* str) {
        append(BasicString<T>(str));
    }
    void append(const T* str, size_t n) {
        append(BasicString<T>(str, n));
    }
    void append(size_t n, T c) {
        append(BasicString<T>(n, c));
    }
    void append(iterator first, iterator last) {
        append(BasicString<T>(first, last));
    }
    void swap(BasicString<T>& str) {
        std::swap((*this).m_buffer, str.m_buffer);
        std::swap((*this).m_size, str.m_size);
    }

    // string operations
    const T* c_str() const {
        return m_buffer;
    }
    virtual int compare(const BasicString<T>& str) const {
        size_t lhs_size = m_size;
        size_t rhs_size = str.m_size;
        int result = std::char_traits<T>::compare(m_buffer, str.m_buffer, std::min(lhs_size, rhs_size));
        if (result != 0)
            return result;
        if (lhs_size < rhs_size)
            return -1;
        if (lhs_size > rhs_size)
            return 1;
        else
            return 0;
    }
    virtual int compare(const T* str) const {
        return compare(BasicString<T>(str));
    }

protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};

} // end namespace CBL

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> res(lhs);
    return res += rhs;
}
template <class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> _lhs(lhs);
    return (_lhs + rhs);
}
template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    CBL::BasicString<T> _rhs(rhs);
    return (lhs + _rhs);
}
template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> _lhs(1, lhs);
    return (_lhs + rhs);
}
template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    CBL::BasicString<T> _rhs(1, rhs);
    return (lhs + _rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    if (lhs.length() != rhs.length()) return false;
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    const CBL::BasicString<T> _lhs(lhs);
    return (_lhs == rhs);
}
template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return (rhs == lhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template <class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    const CBL::BasicString<T> _lhs(lhs);
    return _lhs < rhs;
}
template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return rhs < lhs;
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}
template <class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}
template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}
template <class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}
template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs <= rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template <class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs < rhs);
}
