#include "uniqueWords.h"

void uniqueWords(const std::set<std::string>& uWords,
                 const std::string& file_name) {
    std::ofstream file(file_name);

    for (const auto word : uWords) {
        file << word << '\n';
    }
}
