#ifndef BUCKSHOT_ROULETTE_INVERTER_H
#define BUCKSHOT_ROULETTE_INVERTER_H

#include "item.h"

class Inverter : public Item {
public:
    Inverter();

    void use() final;
};

#endif