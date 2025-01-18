#include "input.h"

bool getInputBool() {
    unsigned int x;
    do {
        std::cin.clear();
        std::cin.sync();
        std::cin >> x;
    } while (std::cin.fail() || x > 1);
    return x;
}

int getCorrectInt(int min, int max) {
    int x;
    do {
        std::cin.clear();
        std::cin.sync();
        std::cin >> x;
    } while (std::cin.fail() || x > max || x < min);
    return x;
}