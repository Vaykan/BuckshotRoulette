#ifndef BUCKSHOT_ROULETTE_GAMETABLE_H
#define BUCKSHOT_ROULETTE_GAMETABLE_H


class GameTable {
    bool isGameOver = false;
public:
    bool getIsGameOver() const;
    void setIsGameOver(bool isGameOver);
};


#endif
