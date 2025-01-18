#ifndef BUCKSHOT_ROULETTE_PHONE_H
#define BUCKSHOT_ROULETTE_PHONE_H

#include "item.h"

class Phone : public Item {
public:
    Phone();

    void use() final;
};

#endif