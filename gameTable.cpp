#include "gameTable.h"

bool GameTable::getIsGameOver() const {
    return isGameOver;
}

void GameTable::setIsGameOver(bool isGameOver) {
    this->isGameOver = isGameOver;
}
