#include "WordCount.h"
#include <fstream>
#include <sstream>

WordCount::WordCount() : count(0) {}

void WordCount::countWords(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        ++count;
    }
    file.close();
}

int WordCount::getCount() const {
    return count;
}
