#include <set>
#include <algorithm>
#include <iostream>
#include "encoder.h"

encoder::encoder() : freq() {
    for (size_t i = 0; i < MAX_VERTEX; ++i) {
        parent[i] = -1;
        children[i].first = children[i].second = -1;
    }
}

void encoder::build_tree() {
    std::set<std::pair<int, int> > sorted;
    for (size_t i = 0; i < ALPHABET; ++i) {
        sorted.insert(std::make_pair(freq[i], i));
    }
    int cur = ALPHABET;
    for (size_t i = 0; i < ALPHABET - 1; ++i) {
        std::pair<int, int> v1 = *sorted.begin();
        sorted.erase(v1);
        std::pair<int, int> v2 = *sorted.begin();
        sorted.erase(v2);
        parent[v1.second] = parent[v2.second] = cur;
        children[cur].first = v1.second;
        children[cur].second = v2.second;
        sorted.insert(std::make_pair(v1.first + v2.first, cur++));
    }
    for (size_t i = 0; i < ALPHABET; ++i) {
        int cur_vertex = i;
        int cur_parent = parent[i];
        while (cur_parent != -1) {
            codes[i].push_back(children[cur_parent].first != cur_vertex);
            cur_vertex = cur_parent;
            cur_parent = parent[cur_vertex];
        }
        reverse(codes[i].begin(), codes[i].end());
    }
}

void encoder::compress(std::vector<unsigned char> const &text, std::vector<unsigned char> &encoded_text) {
    int cnt = 0;
    unsigned new_symb = 0;
    for (unsigned char i : text) {
        int symb = (int)i;
        for (auto && j : codes[symb]) {
            new_symb <<= 1u;
            new_symb += j;
            ++cnt;
            if (cnt == 8) {
                encoded_text.push_back(static_cast<unsigned char>(new_symb));
                cnt = 0;
                new_symb = 0;
            }
        }
    }
    while (cnt > 0 && cnt < 8) {
        new_symb <<= 1u;
        ++cnt;
    }
    if (cnt != 0) {
        encoded_text.push_back(static_cast<unsigned char>(new_symb));
    }
}

std::vector<int> encoder::get_freq() const{
    std::vector<int> frequencies;
    for (int i : freq) {
        frequencies.push_back(i);
    }
    return frequencies;
}

void encoder::set_freq(std::vector<unsigned char> const &text) {
    for (unsigned char i : text) {
        ++freq[i];
    }
}