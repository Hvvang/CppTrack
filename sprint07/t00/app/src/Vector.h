#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>

namespace CBL {

template <class T>
class Vector {
public:
    using iterator = T*;

    Vector() {};
    explicit Vector(size_t size);
    Vector(size_t size, const T& value);
    Vector(iterator first, iterator last);
    Vector(const std::initializer_list<T>& lst);
    Vector(const Vector<T>& other);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& other);
    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;
    bool operator<(const Vector<T>& other) const;
    bool operator>(const Vector<T>& other) const;
    bool operator<=(const Vector<T>& other) const;
    bool operator>=(const Vector<T>& other) const;

    // iterators
    iterator begin() const;
    iterator end() const;

    // capacity
    size_t size() const;
    size_t capacity() const;
    bool isEmpty() const;
    void resize(size_t size, const T& value = T());
    void reserve(size_t size);

    // element access
    T& operator[](size_t index) const;
    T& at(size_t index) const;
    // modifiers
    void push_back(const T& value);

    T* data() const;
    void pop_back();
    iterator insert(iterator pos, const T& value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    void clear();

private:
    size_t m_size {0};
    size_t m_capacity {0};
    T* m_buffer {nullptr};
};


// ************************************** //
// ************ Constructors ************ //
// ************************************** //

    template <class T>
    Vector<T>::Vector(size_t size) {
        m_size = size;
        m_capacity = size;
        m_buffer = new T[size];
    }
    template <class T>
    Vector<T>::Vector(size_t size, const T& value) : Vector(size) {
        for (auto& item : *this) {
            item = value;
        }
    }
    template <class T>
    Vector<T>::Vector(iterator first, iterator last) : Vector(std::distance(first, last)) {
       std::copy(first, last, this->begin());
    }
    template <class T>
    Vector<T>::Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
        std::copy(lst.begin(), lst.end(), this->begin());
    }
    template <class T>
    Vector<T>::Vector(const Vector<T>& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buffer = new T[m_size];
        std::copy(other.begin(), other.end(), this->begin());
    }

// ************************************** //
// ************* Destructor ************* //
// ************************************** //

    template <class T>
    Vector<T>::~Vector() {
    if (m_buffer != nullptr) {
        delete[] m_buffer;
    }
};

// ************************************** //
// ************* Operators ************** //
// ************************************** //

    template <class T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
        if (!(this == &other)) {
            if (other.size() <= m_capacity) {
                std::copy(other.begin(), other.end(), begin());
                m_size = other.size();
            }
            else {
                Vector<T> temp(other);
                std::swap(temp.m_size, m_size);
                std::swap(temp.m_capacity, m_capacity);
                std::swap(temp.m_buffer, m_buffer);
            }
        }
        return *this;
    }
    template <class T>
    bool Vector<T>::operator==(const Vector<T>& other) const {
        if (size() != other.size()) return false;
        return std::equal(this->begin(), this->end(), other.begin(), other.end());
    }
    template <class T>
    bool Vector<T>::operator!=(const Vector<T>& other) const {
        return !(*this == other);
    }
    template <class T>
    bool Vector<T>::operator<(const Vector<T>& other) const {
        return std::lexicographical_compare(this->begin(),
                                            this->end(),
                                            other.begin(),
                                            other.end());
    }
    template <class T>
    bool Vector<T>::operator>(const Vector<T>& other) const {
        return !(*this < other) && (*this != other);
    }
    template <class T>
    bool Vector<T>::operator<=(const Vector<T>& other) const {
        return !(*this > other);
    }
    template <class T>
    bool Vector<T>::operator>=(const Vector<T>& other) const {
        return !(*this < other);
    }

// ************************************** //
// ************* Iterators ************** //
// ************************************** //

    template <class T>
    typename Vector<T>::iterator Vector<T>::begin() const {
        return m_buffer;
    }
    template <class T>
    typename Vector<T>::iterator Vector<T>::end() const {
        return m_buffer + m_size;
    }

// ************************************** //
// ************** Capacity ************** //
// ************************************** //

    template <class T>
    size_t Vector<T>::size() const {
        return m_size;
    }
    template <class T>
    size_t Vector<T>::capacity() const {
        return m_capacity;
    }
    template <class T>
    bool Vector<T>::isEmpty() const {
        return m_size == 0;
    }
    template <class T>
    void Vector<T>::resize(size_t size, const T& value) {
    reserve(size);
    if (size > m_size) {
        size -= m_size;
        for (; size != 0; --size) {
            push_back(value);
        }
    }
    else {
        m_size -= size;
    }
}
    template <class T>
    void Vector<T>::reserve(size_t size) {
        if (size <= m_capacity) return;
        T* p = new T[size];
        std::copy(this->begin(), this->end(), p);
        delete[] m_buffer;
        m_buffer = p;
        m_capacity = size;
    }

// ************************************** //
// *********** Element access *********** //
// ************************************** //

    template <class T>
    T& Vector<T>::operator[](size_t index) const {
        return this->m_buffer[index];
    }
    template <class T>
    T& Vector<T>::at(size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("vector");
        } else {
            return this->m_buffer[index];
        }
    }
    template <class T>
    T* Vector<T>::data() const {
        return m_buffer;
    }

// ************************************** //
// ************* Modifiers ************** //
// ************************************** //

    template <class T>
    void Vector<T>::push_back(const T& value) {
    if (m_size >= m_capacity) {
        auto capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
        auto p = new T[capacity];
        std::copy(this->begin(), this->end(), p);
        delete[] m_buffer;
        m_buffer = p;
        m_capacity = capacity;
    }
    m_buffer[m_size++] = value;
}
    template <class T>
    void Vector<T>::pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }
    template <class T>
    typename Vector<T>::iterator Vector<T>::insert(iterator pos, const T& value) {
        if (pos == this->end()) {
            push_back(value);
            return this->end() - 1;
        }

        auto res = pos - begin();

        Vector<T> temp(begin(), pos);
        temp.push_back(value);
        auto it = pos;
        for (; it != end(); it++) {
            temp.push_back(*it);
        }
        delete[] m_buffer;
        m_capacity *= m_size == m_capacity ? 2 : 1;
        m_buffer = new T[m_capacity];
        std::move(temp.begin(), temp.end(), m_buffer);
        m_size++;
        return begin() + res;
    }
    template <class T>
    typename Vector<T>::iterator Vector<T>::erase(iterator pos) {
        if (pos == this->end() - 1) {
            m_size -= 1;
            return this->end();
        }
        for (auto it = pos; it + 1 != end(); it++) {
            *it = *(it + 1);
        }
        m_size -= 1;
        return pos;
    }
    template <class T>
    typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last) {
        auto b = first;
        auto e = last;
        for (; e != this->end(); b++, e++) {
            *b = *e;
        }
        m_size -= (last - first);
        if (m_size == 0) {
            return nullptr;
        }
        return last;
    }
    template <class T>
    void Vector<T>::clear() {
        m_size = 0;
    }

} // end namespace CBL
