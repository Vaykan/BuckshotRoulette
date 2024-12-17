#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H

#include <vector>

#include "items/item.h"
#include "shotgun.h"

class Item;


class Player {
private:
    int hitPoint = 0;
    int maxHitPoint = 0;
    std::vector<Item> item;
    Shotgun* shotgun;
    Player* target;

public:
    void setHitPoint(int hitPoint);
    int getHitPoint() const;
    void changeHitPoint(int delta);

    void setMaxHitPoint(int maxHitPoint);
    void setArrayItemSize(int size);
    void setTarget(Player& target);
    void setShotgun(Shotgun& shotgun);

    int getMaxHitPoint() const;


};

#endif
