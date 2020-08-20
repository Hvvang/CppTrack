#include "countUniqueWords.h"

void wordMatching(std::string& input, std::multiset<std::string>& uWords,
                  std::smatch& match, const std::regex& pattern) {
    while (std::regex_search(input, match, pattern)) {
        uWords.insert(match.str(0));
        input = match.suffix();
    }
}
