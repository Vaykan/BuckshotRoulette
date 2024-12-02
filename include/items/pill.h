#ifndef BUCKSHOT_ROULETTE_PILL_H
#define BUCKSHOT_ROULETTE_PILL_H

#include "items/item.h"

class Pill : public Item {
public:
    Pill();
    void use(Player &subjectPlayer, Player &objectPlayer, Shotgun &shotgun) override;
};


#endif
