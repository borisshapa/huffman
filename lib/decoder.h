#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <vector>
#include <queue>
#include <bitset>

struct decoder {
    static unsigned const ALPHABET = (1u << 8u);
    explicit decoder(const std::vector<int> &frequencies);
    void build_tree();
    void append_buff(unsigned char s);
    std::pair <bool, unsigned char> get_symb_from_buff();
    bool is_empty_buff();
    void clear_buff();
private:
    static const int MAX_VERTEX = ALPHABET << 1u;
    int symbols[ALPHABET];
    int parent[MAX_VERTEX];
    std::pair <int, int> children[MAX_VERTEX];
    int freq[ALPHABET];
    int root;
    std::queue <bool> buff;
    int cur_vrtx;
};

#endif //HUFFMAN_DECODER_H
