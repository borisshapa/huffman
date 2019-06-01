#ifndef HUFFMAN_UTIL_H
#define HUFFMAN_UTIL_H

#include <cstdio>
#include <stdexcept>
#include <vector>

struct file_reader {
    static const int BUFF = (1 << 16);
    file_reader (const char *filename, const char *mode);
    ~file_reader();
    bool read_char(unsigned char &c);
    template <typename T> bool read_block(size_t size, std::vector <T> &text);
    template <typename T> void write_block(std::vector<T> const &text, const char *sep);
    void reopen();
private:
    FILE *file;
    char mode;
};

#endif //HUFFMAN_UTIL_H
