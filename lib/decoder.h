#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <vector>
#include <queue>
#include <bitset>

struct decoder {
    static unsigned const ALPHABET = (1u << 8u);
    explicit decoder(std::vector<int> const &frequencies);
    void set_buffer(unsigned char s);
    std::pair <bool, unsigned char> get_buffer();
    bool is_empty_buff() const;
    void clear_buff();
private:
    static const int MAX_VERTEX = ALPHABET << 1u;
    int parent[MAX_VERTEX];
    std::pair <int, int> children[MAX_VERTEX];
    int freq[ALPHABET];
    std::queue <bool> buff;
    int root;
    int cur_vrtx;
};

#endif //HUFFMAN_DECODER_H
