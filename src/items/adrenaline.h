#ifndef BUCKSHOT_ROULETTE_ADRENALINE_H
#define BUCKSHOT_ROULETTE_ADRENALINE_H

#include "item.h"

class Adrenaline : public Item {
public:
    Adrenaline();

    void use() final;
    bool isUsable() final;
};

#endif