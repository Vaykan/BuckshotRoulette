#ifndef BUCKSHOT_ROULETTE_MAGNIFIER_H
#define BUCKSHOT_ROULETTE_MAGNIFIER_H

#include "item.h"

class Magnifier : public Item {
public:
    Magnifier();

    void use() final;
};

#endif