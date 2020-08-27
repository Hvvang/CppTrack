# CBL::Vector
### Custom implementation of std::vector.

### Constructors and Destructor
- ```template <class T> Vector();```
- ```template <class T> explicit Vector(size_t size);```
- ```template <class T> Vector(size_t size, const T& value);```
- ```template <class T> Vector(iterator first, iterator last);```
- ```template <class T> Vector(const std::initializer_list<T>& lst);```
- ```template <class T> Vector(const Vector<T>& other);```
- ```template <class T> ~Vector();```


### Operators
- ```template <class T> Vector<T>& operator=(const Vector<T>& other);```
- ```template <class T> bool operator==(const Vector<T>& other) const;```
- ```template <class T> bool operator!=(const Vector<T>& other) const;```
- ```template <class T> bool operator<(const Vector<T>& other) const;```
- ```template <class T> bool operator>(const Vector<T>& other) const;```
- ```template <class T> bool operator<=(const Vector<T>& other) const;```
- ```template <class T> bool operator>=(const Vector<T>& other) const;```

### Iterators
- ```template <class T> iterator begin() const;```
- ```template <class T> iterator end() const;```
    
### Capacity 
- ```template <class T> size_t size() const;```
- ```template <class T> size_t capacity() const;```
- ```template <class T> bool isEmpty() const;```
- ```template <class T> void resize(size_t size, const T& value = T());```
- ```template <class T> void reserve(size_t size);```

### Element access
- ```template <class T> T& operator[](size_t index) const;```
- ```template <class T> T& at(size_t index) const;```
- ```template <class T> T* data() const;```
    
    
### Modifiers
- ```template <class T> void push_back(const T& value);```
- ```template <class T> void pop_back();```
- ```template <class T> iterator insert(iterator pos, const T& value);```
- ```template <class T> iterator erase(iterator pos);```
- ```template <class T> iterator erase(iterator first, iterator last);```
- ```template <class T> void clear();```
    


    
    
    
    
    
    
    
    
