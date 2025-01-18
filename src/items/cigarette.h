#ifndef BUCKSHOT_ROULETTE_CIGARETTE_H
#define BUCKSHOT_ROULETTE_CIGARETTE_H

#include "item.h"

class Cigarette : public Item {
public:
    Cigarette();

    void use() final;
};

#endif