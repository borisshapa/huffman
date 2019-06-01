#include <iostream>
#include "util.h"
#include <string.h>
#include <stdio.h>

file_reader::file_reader(const char *filename, const char *mode) {
    file = fopen(filename, mode);
    if (file == nullptr) {
        throw std::runtime_error("error opening");
    }
    this->mode = mode[0];
}

template<>
bool file_reader::read_block(size_t size, std::vector<unsigned char> &text) {
    text.clear();
    text.resize(size);
    size_t cnt_read = fread(text.data(), 1, size, file);
    text.erase(text.begin() + cnt_read, text.end());
    if (ferror(file)) {
        throw std::runtime_error("error reading");
    }
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
    if (ferror(file)) {
        throw std::runtime_error("error reading");
    }
    return !text.empty();
}

template<>
void file_reader::write_block(std::vector<unsigned char> const &text, const char *sep) {
    int i = 0;
    while (i < (int) text.size()) {
        fprintf(file, "%c%s", text[i], sep);
        ++i;
    }
    if (ferror(file)) {
        throw std::runtime_error("error writing");
    }
}

template<>
void file_reader::write_block(std::vector<int> const &text, const char *sep) {
    int i = 0;
    while (i < (int) text.size()) {
        fprintf(file, "%d%s", text[i], sep);
        ++i;
    }
    if (ferror(file)) {
        throw std::runtime_error("error writing");
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
