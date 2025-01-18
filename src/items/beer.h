#ifndef BUCKSHOT_ROULETTE_BEER_H
#define BUCKSHOT_ROULETTE_BEER_H

#include "item.h"

class Beer : public Item {
public:
    Beer();

    void use() final;
};

#endif