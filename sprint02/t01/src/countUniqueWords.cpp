#include "countUniqueWords.h"

void countUniqueWords(const std::multiset<std::string>& uWords,
                      const std::string& file_name) {
    std::ofstream file(file_name);
    std::string prev;
    for (const auto& word : uWords) {
        if (prev != word) {
            file << word << ": " << uWords.count(word) << '\n';
            prev = word;
        }
    }
}
