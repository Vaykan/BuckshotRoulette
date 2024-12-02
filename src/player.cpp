#include "player.h"

void Player::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

int Player::getHitPoint() const {
    return hitPoint;
}

void Player::changeHitPoint(int delta) {
    int newHitPoint = hitPoint + delta;
    if (newHitPoint > maxHitPoint) {
        newHitPoint = maxHitPoint;
    }else if (newHitPoint < 0) {
        newHitPoint = 0;
    }
    setHitPoint(newHitPoint);
}

void Player::setArrayItemSize(int size) {
    item.resize(size);
}

void Player::setMaxHitPoint(int maxHitPoint) {
    this->maxHitPoint = maxHitPoint;
}

int Player::getMaxHitPoint() const {
    return maxHitPoint;
}