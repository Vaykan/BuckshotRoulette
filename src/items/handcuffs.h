#ifndef BUCKSHOT_ROULETTE_HANDCUFFS_H
#define BUCKSHOT_ROULETTE_HANDCUFFS_H

#include "item.h"

class Handcuffs : public Item {
public:
    Handcuffs();

    void use() final;
    bool isUsable() final;
};

#endif