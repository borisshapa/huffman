#include <iostream>
#include "util.h"
#include <string.h>
#include <stdio.h>

file_reader::file_reader(const char *filename, const char *mode) {
    file = fopen(filename, mode);
    this->mode = mode[0];
}

template<typename T>
bool file_reader::read_block(size_t size, std::vector<T> &text) {}

template<>
bool file_reader::read_block(size_t size, std::vector<unsigned char> &text) {
    text.clear();
    text.resize(size);
    size_t cnt_read = fread(text.data(), 1, size, file);
    text.erase(text.begin() + cnt_read, text.end());
    return cnt_read > 0;
}

template<>
bool file_reader::read_block(size_t size, std::vector<int> &text) {
    text.clear();
    int token;
    while (size > 0 && fscanf(file, "%d", &token) > 0) {
        text.push_back(token);
        --size;
    }
    return (int) text.size() > 0;
}

template<typename T>
void file_reader::write_block(std::vector<T> &text, const char *sep) {}

template<>
void file_reader::write_block(std::vector<unsigned char> &text, const char *sep) {
    int i = 0;
    while (i < (int) text.size()) {
        fprintf(file, "%c%s", text[i], sep);
        ++i;
    }
}

template<>
void file_reader::write_block(std::vector<int> &text, const char *sep) {
    int i = 0;
    while (i < (int) text.size()) {
        fprintf(file, "%d%s", text[i], sep);
        ++i;
    }
}

file_reader::~file_reader() {
    fclose(file);
}

bool file_reader::read_char(unsigned char &c) {
    return fscanf(file, "%c", &c) > 0;
}

void file_reader::reopen() {
    rewind(file);
}
