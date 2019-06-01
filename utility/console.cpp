#include "../lib/encoder.h"
#include "../lib/decoder.h"
#include "../utility/util.h"
#include "../utility/console.h"
#include <iostream>
#include <cstring>

void compress(const char *input, const char *output) {
    file_reader in(input, "rb");
    file_reader out(output, "wb");
    std::vector<unsigned char> text;

    encoder en;
    while (in.read_block(file_reader::BUFF, text)) {
        en.set_freq(text);
    }
    std::vector<int> freq;
    en.build_tree();
    en.get_freq(freq);
    out.write_block(freq, " ");

    in.reopen();
    while (in.read_block(file_reader::BUFF, text)) {
        std::vector<unsigned char> encoded_text;
        en.compress(text, encoded_text);
        out.write_block(encoded_text, "");
    }
}

void decompress(const char *input, const char *output) {
    file_reader in(input, "rb");
    file_reader out(output, "wb");
    std::vector<int> freq;
    try {
        in.read_block(256, freq);
    } catch (std::invalid_argument const &e) {
        throw;
    }

    unsigned char end;
    in.read_char(end);
    if (end != ' ') {
        throw std::invalid_argument("expected whitespace after frequencies");
    }

    int cnt = 0;
    for (int i : freq) {
        cnt += i;
        if (i < 0) {
            throw std::invalid_argument("expected correct frequencies");
        }
    }

    decoder dec(freq);
    while (true) {
        bool eof = false;
        std::vector<unsigned char> ans;
        while (static_cast<int>(ans.size()) < file_reader::BUFF && cnt > 0) {
            if (dec.is_empty_buff()) {
                unsigned char symb;
                if (!in.read_char(symb)) {
                    eof = true;
                    break;
                }
                dec.set_buffer(symb);
            }
            std::pair<bool, unsigned char> p = dec.get_buffer();
            if (p.first) {
                ans.push_back(p.second);
                cnt--;
            }
        }
        dec.clear_buff();
        out.write_block(ans, "");
        if (eof || cnt <= 0) {
            break;
        }
    }
    if (cnt != 0) {
        throw std::invalid_argument("expected correct compressed file");
    }
}
