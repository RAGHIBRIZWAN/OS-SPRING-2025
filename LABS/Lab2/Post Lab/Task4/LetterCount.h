#ifndef LETTERCOUNT_H
#define LETTERCOUNT_H

#include <string>
#include <fstream>

class LetterCount {
private:
    int count;

public:
    LetterCount();
    void countLetters(const std::string& filename);
    int getCount() const;
};

#endif
