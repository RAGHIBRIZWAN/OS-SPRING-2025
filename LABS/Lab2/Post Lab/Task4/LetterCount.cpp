#include "LetterCount.h"
#include <fstream>
#include <cctype>

LetterCount::LetterCount() : count(0) {}

void LetterCount::countLetters(const std::string& filename) {
    std::ifstream file(filename);
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            ++count;
        }
    }
    file.close();
}

int LetterCount::getCount() const {
    return count;
}
