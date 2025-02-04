#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <string>
#include <fstream>
#include <sstream>

class WordCount {
private:
    int count;

public:
    WordCount();
    void countWords(const std::string& filename);
    int getCount() const;
};

#endif
