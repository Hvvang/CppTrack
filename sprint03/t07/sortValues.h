#pragma once

#include <iterator>
#include <algorithm>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    if (auto size = std::distance(begin, end); size > 1) {
        std::vector<typename RandomAccessIterator::value_type> v(begin, end);
        auto middle = next(v.begin(), size / 2);

        sortValues(v.begin(), middle);
        sortValues(middle, v.end());
        std::merge(v.begin(), middle, middle, v.end(), begin);
    }
    return begin;
}
