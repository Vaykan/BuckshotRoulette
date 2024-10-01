#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H

#include <vector>

#include "item.h"


class Player {
    int hitPoint = 0;
    std::vector<Item> item;
public:
    void setHitPoint(int hitPoint);
    int getHitPoint() const;
    void setDamage(int damage);

    void setArrayItemSize(int size);
};


#endif //BUCKSHOT_ROULETTE_PLAYER_H
