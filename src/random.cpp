#include "random.h"

int lastMin = 0;
int lastMax = 0;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(lastMin, lastMax);
std::uniform_int_distribution<> distBit(0, 1);

int rGetNum(int min, int max) {
    /*if(!(lastMin == min && lastMax == max)){
        dist = std::uniform_int_distribution<>(min, max);
        lastMin = min;
        lastMax = max;
    }*/
    dist = std::uniform_int_distribution<>(min, max);
    return dist(gen);
}

int rGetRandBit() {
    return distBit(gen);
}