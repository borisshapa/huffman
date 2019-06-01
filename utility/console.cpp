#include "../lib/encoder.h"
#include "../lib/decoder.h"
#include "../utility/util.h"
#include "../utility/console.h"
#include <iostream>
#include <cstring>

void compress(const char *input, const char *output) {
    FileUtil in(input, "rb");
    FileUtil out(output, "wb");
    std::vector<unsigned char> text;

    encoder en;
    while (in.read_block(FileUtil::MAX_CHAR, text)) {
        en.set_freq(text);
    }
    std::vector<int> freq;
    en.build_tree();
    en.get_freq(freq);
    out.write_block(freq, " ");

    in.reopen();
    while (in.read_block(FileUtil::MAX_CHAR, text)) {
        std::vector<unsigned char> encoded_text;
        en.encode(text, encoded_text);
        out.write_block(encoded_text, "");
    }
}

void decompress(const char *input, const char *output) {
    FileUtil in(input, "rb");
    FileUtil out(output, "wb");
    std::vector<int> freq;
    try {
        in.read_block(256, freq);
    } catch (std::invalid_argument const &e) {
        throw;
    }

    unsigned char end;
    in.read_char(end);
    if (end != ' ') {
        throw std::invalid_argument("wrong file to decompress");
    }

    int cnt = 0;
    for (int i : freq) {
        cnt += i;
        if (i < 0) {
            throw std::invalid_argument("wrong file to decompress");
        }
    }

    decoder dec(freq);
    while (true) {
        bool eof = false;
        std::vector<unsigned char> ans;
        while ((int) ans.size() < FileUtil::MAX_CHAR && cnt > 0) {
            if (dec.is_empty_buff()) {
                unsigned char symb;
                if (!in.read_char(symb)) {
                    eof = true;
                    break;
                }
                dec.append_buff(symb);
            }
            std::pair<bool, unsigned char> p = dec.get_symb_from_buff();
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
        throw std::invalid_argument("wrong file to decompress");
    }
}
