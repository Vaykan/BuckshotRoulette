#include <random>

#include "random.h"

using namespace std;

int rGetNum(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

ShellType rGetRandShellType() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1);
    int number = dist(gen);
    if(number == 0)
        return LIVE;
    return BLANK;
}