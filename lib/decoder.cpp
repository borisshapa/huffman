#include <set>
#include <cstring>
#include "decoder.h"

decoder::decoder(const std::vector<int> &frequencies) {
    for (size_t i = 0; i < ALPHABET; i++) {
        freq[i] = frequencies[i];
    }
    for (size_t i = 0; i < MAX_VERTEX; ++i) {
        parent[i] = -1;
        children[i].first = children[i].second = -1;
    }

    std::set<std::pair<int, int> > sorted;
    for (size_t i = 0; i < ALPHABET; ++i) {
        sorted.insert(std::make_pair(freq[i], i));
    }
    int cur = ALPHABET;
    for (size_t i = 0; i < ALPHABET - 1; ++i) {
        std::pair <int, int> v1 = *sorted.begin();
        sorted.erase(v1);
        std::pair <int, int> v2 = *sorted.begin();
        sorted.erase(v2);
        parent[v1.second] = parent[v2.second] = cur;
        children[cur].first = v1.second;
        children[cur].second = v2.second;
        sorted.insert(std::make_pair(v1.first + v2.first, cur++));
    }
    root = cur - 1;
    cur_vrtx = root;
}

void decoder::set_buffer(unsigned char s) {
    for (int i = 7; i >= 0; i--) {
        buff.push((s >> i) & 1);
    }
}

std::pair<bool, unsigned char> decoder::get_buffer() {
    while (!is_empty_buff()) {
        if (children[cur_vrtx] != std::make_pair(-1, -1)) {
            if (buff.front()) {
                cur_vrtx = children[cur_vrtx].second;
            } else {
                cur_vrtx = children[cur_vrtx].first;
            }
            buff.pop();
        } else {
            int tmp = cur_vrtx;
            cur_vrtx = root;
            return std::make_pair(true, static_cast<unsigned char>(tmp));
        }
    }
    if (children[cur_vrtx] == std::make_pair(-1, -1)) {
        int tmp = cur_vrtx;
        cur_vrtx = root;
        return std::make_pair(true, static_cast<unsigned char>(tmp));
    }
    return std::make_pair(false, 0);
}

bool decoder::is_empty_buff() {
    return buff.empty();
}

void decoder::clear_buff() {
    while (!buff.empty()) {
        buff.pop();
    }
}
