#ifndef BUCKSHOT_ROULETTE_CIGARETTE_H
#define BUCKSHOT_ROULETTE_CIGARETTE_H


#include "items/item.h"

class Cigarette : public Item {
public:
    Cigarette();
    void use(Player &subjectPlayer, Player &objectPlayer) override;
};


#endif