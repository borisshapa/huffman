#ifndef HUFFMAN_UTIL_H
#define HUFFMAN_UTIL_H

#include <cstdio>
#include <stdexcept>
#include <vector>

struct FileUtil {
    static const int MAX_CHAR = (1 << 16);
    FileUtil (const char *filename, const char *mode);
    ~FileUtil();
    bool read_char(unsigned char &c);
    template <typename T> bool read_block(int size, std::vector <T> &text);
    template <typename T> void write_block(std::vector<T> &text, const char *sep);
    void reopen();
private:
    FILE *file;
    char mode;
};

#endif //HUFFMAN_UTIL_H
