#ifndef BUCKSHOT_ROULETTE_SAW_H
#define BUCKSHOT_ROULETTE_SAW_H

#include "item.h"

class Saw : public Item{
public:
    Saw();
    void use() final;
};


#endif
