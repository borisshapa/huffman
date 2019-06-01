#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include <vector>
#include <bitset>

struct encoder {
    static unsigned const ALPHABET = (1u << 8u);
    encoder();
    void build_tree();
    void compress(std::vector<unsigned char> const &, std::vector<unsigned char> &);
    std::vector<int> get_freq() const;
    void set_freq(std::vector<unsigned char> const &);
private:
    int freq[ALPHABET];
    static unsigned const MAX_VERTEX = (ALPHABET << 1u);
    int parent[MAX_VERTEX];
    std::pair <int, int> children[MAX_VERTEX];
    std::vector<bool> codes[ALPHABET];
};


#endif //HUFFMAN_ENCODER_H
