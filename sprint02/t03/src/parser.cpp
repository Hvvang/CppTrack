#include "tesLibrary.h"

void trimToQuote(std::string& line) {
    std::regex pattern("\".+\"");
    std::smatch match;
    std::string temp;

    if (std::regex_search(line, match, pattern)) {
        temp = match.str(0);
    }
    line = temp.substr(1, temp.length() - 2);
}

void parser(std::multimap<std::string, std::string>& content, std::string& line) {
    std::regex pattern("\".+\"( )*:");
    std::smatch match;

    std::string author;
    std::string book;

    if (std::regex_search(line, match, pattern)) {
        author = match.str(0);
        book = match.suffix();
        trimToQuote(author);
        trimToQuote(book);

        content.insert(std::pair<std::string, std::string>(author, book));
    }
}
