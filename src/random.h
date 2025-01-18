#ifndef BUCKSHOT_ROULETTE_RANDOM_H
#define BUCKSHOT_ROULETTE_RANDOM_H

#include <random>

int rGetNum(int min, int max);
int rGetRandBit();

extern int lastMin;
extern int lastMax;

extern std::random_device rd;
extern std::mt19937 gen;
extern std::uniform_int_distribution<> dist;
extern std::uniform_int_distribution<> distBit;

#endif