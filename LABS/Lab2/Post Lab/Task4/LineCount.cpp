#include "LineCount.h"
#include <fstream>

LineCount::LineCount() : count(0) {}

void LineCount::countLines(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        ++count;
    }
    file.close();
}

int LineCount::getCount() const {
    return count;
}
