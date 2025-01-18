#ifndef BUCKSHOT_ROULETTE_SHOTGUN_H
#define BUCKSHOT_ROULETTE_SHOTGUN_H

#include <vector>
#include <iostream>

#include "random.h"
#include "enum.h"
#include "player.h"

class Player;

class Shotgun {
private:
    bool doubleDamage = false;

    std::vector<ShellType> magazine;
public:
    void setDoubleDamage(bool doubleDamage);
    bool isDoubleDamage() const;

    void shoot(Player* target);
    void pumping();
    void loading(int count);

    void setSizeMagazine(int size);
    void displayMagazineContents();
    bool isEmpty();
    ShellType& getBackShell();
    std::vector<ShellType>& getMagazine();
};

#endif