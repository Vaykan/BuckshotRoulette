#include "player.h"
#include "item.h"

void Player::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

int Player::getHitPoint() const {
    return hitPoint;
}

void Player::setDamage(int damage) {
    hitPoint = hitPoint - damage;
}

void Player::setArrayItemSize(int size) {
    item.resize(size);
}
