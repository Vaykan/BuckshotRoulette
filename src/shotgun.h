#ifndef BUCKSHOT_ROULETTE_SHOTGUN_H
#define BUCKSHOT_ROULETTE_SHOTGUN_H

#include <vector>
#include <iostream>

#include "random.h"
#include "enum.h"
#include "player.h"

class Player;
class Session;

class Shotgun {
private:
    ShellType previousShellType;
    bool doubleDamage = false;
    Session* session = nullptr;
    std::vector<ShellType> magazine;
public:
    static const int MAX_MAGAZINE = 8;

    ShellType getPreviousShellType();

    void setDoubleDamage(bool doubleDamage);

    void shoot(Player* target);
    void pumping();
    void loading(int count);

    void displayMagazineContents();
    bool isEmpty();
    ShellType& getBackShell();
    std::vector<ShellType>& getMagazine();

    void setSession(Session& session);
};

#endif