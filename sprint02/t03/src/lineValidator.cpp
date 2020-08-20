#include "tesLibrary.h"

void lineValidator(char *filePath) {
    std::ifstream file(filePath);
    std::multimap<std::string, std::string> content;
    std::string line;

    if (file.is_open()) {
        std::regex pattern("\"(.)+\"( )*:( )*\"(.)+\"");
        std::smatch match;
        int lineCounter = 0;

        while (getline(file, line)) {
            lineCounter++;
            if (line.length()) {
                if (std::regex_search(line, match, pattern)) {
                    parser(content, line);
                } else {
                    std::cerr << "Line " << lineCounter <<
                                 " is invalid" << "\n";
                    return;
                }
            }
        }
        file.close();
        printContent(content);
    } else {
        std::cerr << "error" << "\n";
    }
}
