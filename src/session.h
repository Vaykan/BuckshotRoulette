#ifndef BUCKSHOT_ROULETTE_SESSION_H
#define BUCKSHOT_ROULETTE_SESSION_H

#include "player.h"
#include "shotgun.h"
#include "items/item.h"
#include "items/pill.h"
#include "items/cigarette.h"
#include "input.h"

class Player;
class Shotgun;


class Session {
private:
    Player dealer, player;
    Shotgun shotgun;

public:

    void config();
    void start();

    void giveTurn(Player& subject);

    void setDealer(Player& dealer);
    void setPlayer(Player& player);
};

#endif
