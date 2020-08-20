#pragma once

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    for ( ; begin != end - 1; ) {
        if (*begin != *(end - 1)) {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}
