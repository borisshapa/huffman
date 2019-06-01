#include <random>

#include <iomanip>
#include "../utility/console.h"
#include <numeric>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

char *input = (char *) ("input.txt");
char *tmp = (char *) ("compressed.txt");
char *res = (char *) ("decompressed.txt");

size_t test_num = 0;

bool check_test() {
    test_num++;
    bool answ = true;
    auto start_time = clock();
    compress(input, tmp);
    decompress(tmp, res);
    double test_time = (clock() - start_time);
    std::ifstream fin(res);
    std::ifstream finp(input);
    char c1, c2;
    while (fin.get(c1) && answ) {
        if (finp.get(c2)) {
            answ = (c1 == c2);
        } else {
            answ = false;
        }
    }
    if (!fin.get(c1) && finp.get(c2)) {
        answ = false;
    }
    std::cerr << "[RUN   ] Test #" << test_num << "\n";
    if (answ)
        std::cerr << "[    OK] " << test_time / CLOCKS_PER_SEC << " sec." << "\n\n";
    else
        std::cerr << "[FAILED] Test #" << test_num << "\n\n";
    return answ;
}

void finish_test(std::ofstream &out) {
    out.close();
    check_test();
    out.open(input);
}

void test() {
    std::ofstream fout(input);

    // Test #1
    check_test();

    // Test #2
    fout << "a";
    finish_test(fout);

    // Test #3
    fout << "abc";
    finish_test(fout);

    // Test #4
    for (int i = 0; i < 26; i++)
        fout << char('a' + i);
    finish_test(fout);

    // Test #5
    for (int i = 0; i < 256; i++)
        fout << char(i);
    finish_test(fout);

    // Test #6
    fout << "no pain, no gain, again";
    finish_test(fout);

    // Test #7
    fout << "Is this the real life?\n"
            "Is this just fantasy?\n"
            "Caught in a landslide\n"
            "No escape from reality\n"
            "Open your eyes\n"
            "Look up to the skies and see\n"
            "I'm just a poor boy, I need no sympathy\n"
            "Because I'm easy come, easy go\n"
            "A little high, little low\n"
            "Anyway the wind blows, doesn't really matter to me, to me\n"
            "Mama, just killed a man\n"
            "Put a gun against his head\n"
            "Pulled my trigger, now he's dead\n"
            "Mama, life had just begun\n"
            "But now I've gone and thrown it all away\n"
            "Mama, oh oh \n"
            "Didn't mean to make you cry\n"
            "If I'm not back again this time tomorrow\n"
            "Carry on, carry on, as if nothing really matters\n"
            "Too late, my time has come\n"
            "Sends shivers down my spine\n"
            "Body's aching all the time\n"
            "Goodbye everybody I've got to go\n"
            "Gotta leave you all behind and face the truth\n"
            "Mama, oh oh (anyway the wind blows)\n"
            "I don't want to die\n"
            "Sometimes wish I'd never been born at all\n"
            "I see a little silhouetto of a man\n"
            "Scaramouch, Scaramouch will you do the Fandango\n"
            "Thunderbolt and lightning very very frightening me\n"
            "Gallileo, Gallileo, Gallileo, Gallileo, Gallileo, figaro, magnifico\n"
            "I'm just a poor boy and nobody loves me\n"
            "He's just a poor boy from a poor family\n"
            "Spare him his life from this monstrosity\n"
            "Easy come easy go will you let me go\n"
            "Bismillah, no we will not let you go, let him go\n"
            "Bismillah, we will not let you go, let him go\n"
            "Bismillah, we will not let you go, let me go\n"
            "(Will not let you go) let me go (never, never let you go) let me go (never let me go)\n"
            "Oh oh no, no, no, no, no, no, no\n"
            "Oh mama mia, mama mia, mama mia let me go\n"
            "Beelzebub has a devil put aside for me for me for me\n"
            "So you think you can stop me and spit in my eye\n"
            "So you think you can love me and leave me to die\n"
            "Oh baby can't do this to me baby\n"
            "Just gotta get out just gotta get right outta here\n"
            "Oh oh oh yeah, oh oh yeah\n"
            "Nothing really matters\n"
            "Anyone can see\n"
            "Nothing really matters \n"
            "Nothing really matters to me\n"
            "Anyway the wind blows";
    finish_test(fout);

    // Test #8
    for (size_t i = 0; i < 10000; i++)
        fout << 'z';
    finish_test(fout);

    // Test #9
    for (size_t i = 0; i < 256; i++) {
        std::vector<char> g(26);
        std::iota(g.begin(), g.end(), 'a');
        shuffle(g.begin(), g.end(), std::mt19937(std::random_device()()));
        for (char j : g)
            fout << j;
    }
    finish_test(fout);

    // Test #10
    for (size_t i = 0; i < 10000; i++) {
        fout << "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    }
    finish_test(fout);

    // Test #11
    for (size_t i = 0; i < 100; i++) {
        fout << (char) (rand() % 256);
    }
    finish_test(fout);

    // Test #12
    for (size_t i = 0; i < 1000; i++) {
        fout << (char) (rand() % 256);
    }
    finish_test(fout);

    // Test #13
    for (size_t i = 0; i < 10000; i++) {
        fout << (char) (rand() % 256);
    }
    finish_test(fout);

    // Test #14
    for (size_t i = 0; i < 100000; i++) {
        fout << (char) (rand() % 256);
    }
    finish_test(fout);

    // Test #15
    for (size_t i = 0; i < 1000000; i++) {
        fout << (char) (rand() % 256);
    }
    finish_test(fout);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        test();
    } else {
        double time_start = clock();
        if (argc != 4) {
            std::cout << "count of arguments is not equal to 4\n";
            return 0;
        }
        char *mode = argv[1];
        char *input_file = argv[2];
        char *output_file = argv[3];

        if (strcmp(mode, "compress") == 0) {
            compress(input_file, output_file);
        } else if (strcmp(mode, "decompress") == 0) {
            try {
                decompress(input_file, output_file);
            } catch (std::invalid_argument e) {
                std::cout << e.what() << "\n";
                return 0;
            }
        } else {
            std::cout << "incorrect mode\n";
        }
        std::cerr << (clock() - time_start) / CLOCKS_PER_SEC << " seconds.\n";
    }
    return 0;
}