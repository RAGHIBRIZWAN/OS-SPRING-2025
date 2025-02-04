#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    std::string filename = "sample.txt"; // Change the file name as needed

    LetterCount letterCounter;
    letterCounter.countLetters(filename);
    std::cout << "Number of letters: " << letterCounter.getCount() << std::endl;

    WordCount wordCounter;
    wordCounter.countWords(filename);
    std::cout << "Number of words: " << wordCounter.getCount() << std::endl;

    LineCount lineCounter;
    lineCounter.countLines(filename);
    std::cout << "Number of lines: " << lineCounter.getCount() << std::endl;

    return 0;
}
