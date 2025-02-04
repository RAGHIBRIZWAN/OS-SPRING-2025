#ifndef LINECOUNT_H
#define LINECOUNT_H

#include <string>
#include <fstream>

class LineCount {
private:
    int count;

public:
    LineCount();
    void countLines(const std::string& filename);
    int getCount() const;
};

#endif
