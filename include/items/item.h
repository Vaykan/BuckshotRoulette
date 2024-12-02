#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "enum.h"
#include "shotgun.h"
#include "player.h"
#include "random.h"

class Player;

class Item {
protected:
    ItemType itemType;
public:
    Item();
    virtual void healSubject();
    virtual void damageObject();
    
};



#endif
