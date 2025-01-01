#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "../enum.h"
#include "../shotgun.h"
#include "../player.h"
#include "../random.h"

class Player;

class Item {
private:
    Player* owner;
    Player* target;
protected:
    ItemType itemType;
public:
    Item();
    virtual void use();
    virtual void setTarget(Player& target);
    virtual void setOwner(Player& owner);

    
};



#endif
