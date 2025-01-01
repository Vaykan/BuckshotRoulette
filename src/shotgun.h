#ifndef BUCKSHOT_ROULETTE__SHOTGUN_H
#define BUCKSHOT_ROULETTE__SHOTGUN_H

#include "shell.h"

class Shotgun {
public:
    static const int magazineSize = 8;
    Shell *magazine[magazineSize]{nullptr};
    void pumping();
    void loading();

public:

    bool isEmpty();



};

#endif