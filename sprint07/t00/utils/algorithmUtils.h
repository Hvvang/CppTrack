#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <type_traits>

namespace Utils {

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    if (val > to || val < from) {
        return false;
    } else return true;
}

template <typename T>
bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    if (val > minmax.second || val < minmax.first) {
        return false;
    } else return true;
}

template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
    if (val >= to || val <= from) {
        return false;
    } else return true;
}

template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    if (val >= minmax.second || val <= minmax.first) {
        return false;
    } else return true;
}

template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
    if (obj != new_value) {
        obj = new_value;
        return true;
    } else return false;
}

template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
    auto iter = std::remove(std::begin(c), std::end(c), value);
    Collection new_front(std::distance(c.begin(), iter));
    Collection new_back(std::distance(iter, c.end()));

    std::move(c.begin(), iter, new_front.begin());
    std::move(iter, c.end(), new_back.begin());
    c = new_front;
}

template <class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
    auto iter = std::remove_if(std::begin(c), std::end(c), predicate);
    Collection new_front(std::distance(c.begin(), iter));
    Collection new_back(std::distance(iter, c.end()));

    std::move(c.begin(), iter, new_front.begin());
    std::move(iter, c.end(), new_back.begin());
    c = new_front;
}

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (*iter == value) {
            return iter;
        }
    }
    return c.end();
}

template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (predicate(*iter)) {
            return iter;
        }
    }
    return c.end();
}

template <class Collection, class T>
bool Contains(const Collection& c, const T& value) {
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (*iter == value) {
            return true;
        }
    }
    return false;
}

template <class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (predicate(*iter)) {
            return true;
        }
    }
    return false;
}

template <class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
    int count = 0;

    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (predicate(*iter)) {
            count++;
        }
    }
    return count;
}

template <class T, class... Args>
const auto& Min(const T& arg, const Args&... args) {
    std::vector<T> v{arg, args...};
    auto min = v.begin();

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (*min > *iter) {
            min = iter;
        }
    }
    return *min;
}

template <class T, class... Args>
const auto& Max(const T& arg, const Args&... args) {
    std::vector<T> v{arg, args...};
    auto max = v.begin();

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (*max < *iter) {
            max = iter;
        }
    }
    return *max;
}

template <class Collection>
void Sort(Collection& c) {
    std::sort(c.begin(), c.end());
}

template <class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
    std::sort(c.begin(), c.end(), comparator);
}

template <class Collection>
auto MaxElement(const Collection& c) {
    auto max = c.front();

    for (const auto& item : c) {
        if (max < item) {
            max = item;
        }
    }
    return max;
}

template <class Collection>
auto MinElement(const Collection& c) {
    auto min = c.front();

    for (const auto& item : c) {
        if (min > item) {
            min = item;
        }
    }
    return min;
}

template <class Collection, class Comp>
auto MaxElement(const Collection& c, Comp&& comparator) {
    auto max = c.front();

    for (const auto& item : c) {
        if (comparator(max, item)) {
            max = item;
        }
    }
    return max;
}

template <class Collection, class Comp>
auto MinElement(const Collection& c, Comp&& comparator) {
    auto min = c.front();

    for (const auto& item : c) {
        if (comparator(item, min)) {
            min = item;
        }
    }
    return min;
}

template <class Collection>
void Unique(Collection& c) {
    auto it = std::unique(c.begin(), c.end());
    Collection uniqueElements(std::distance(c.begin(), it));
    Collection toDelete(std::distance(it, c.end()));

    std::move(c.begin(), it, uniqueElements.begin());
    std::move(it, c.end(), toDelete.begin());
    c = std::move(uniqueElements);
}

template <class Collection, class Pred>
void Unique(Collection& c, Pred&& predicate) {
    auto it = std::unique(c.begin(), c.end(), predicate);
    Collection uniqueElements(std::distance(c.begin(), it));
    Collection toDelete(std::distance(it, c.end()));

    std::move(c.begin(), it, uniqueElements.begin());
    std::move(it, c.end(), toDelete.begin());
    c = std::move(uniqueElements);
}

template <class Collection, class Pred>
void ForEach(Collection& c, Pred&& predicate) {
    for (auto& item : c) {
        predicate(item);
    }
}

template <class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
    return std::distance(c.begin(), Find(c, value));
}

template <class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
    return std::distance(c.begin(), FindIf(c, predicate));
}

}
