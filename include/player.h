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
    Shotgun *shotgun;

public:
    void setHitPoint(int hitPoint);
    int getHitPoint() const;
    void changeHitPoint(int delta);

    void setMaxHitPoint(int maxHitPoint);
    int getMaxHitPoint() const;

    void setArrayItemSize(int size);
};

#endif
