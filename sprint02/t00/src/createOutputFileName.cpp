#include "uniqueWords.h"

std::string createOutputFileName(char *inFile) {
    std::string input(inFile);
    std::stringstream ss(input);
    std::string tok;
    size_t index;

    while(std::getline(ss, tok, '/'));
    if ((index = tok.rfind(".")) != std::string::npos) {
            tok.insert(index, "_mod");
            return tok;
    } else return tok + "_mod";
}
