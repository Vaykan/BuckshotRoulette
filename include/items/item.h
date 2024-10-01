#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "enum.h"

class Player;

class Item {
protected:
    ItemType itemType;
public:
    Item();
    virtual void use(Player &subjectPlayer, Player &objectPlayer);
};

#endif
