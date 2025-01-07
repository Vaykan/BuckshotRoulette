#ifndef BUCKSHOT_ROULETTE__SHOTGUN_H
#define BUCKSHOT_ROULETTE__SHOTGUN_H

#include <vector>
#include <iostream>

#include "random.h"
#include "enum.h"
#include "player.h"

class Player;

class Shotgun {
private:
    std::vector<ShellType> magazine;
public:
    void shoot(Player* target);
    void pumping();
    void loading(int count);

    void setSizeMagazine(int size);
    bool isEmpty();
};

#endif