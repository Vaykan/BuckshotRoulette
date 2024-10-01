#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "enum.h"

class Player;

class Item {
    ItemType itemType;
public:
    Item();
    virtual void use(Player subject, Player object);
};

class Pill : Item {
    void use (Player subject, Player object) override;
};


#endif
