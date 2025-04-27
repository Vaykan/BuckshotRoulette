#ifndef BUCKSHOT_ROULETTE_SESSION_H
#define BUCKSHOT_ROULETTE_SESSION_H

#include "player.h"
#include "shotgun.h"
#include "input.h"

#include "items/item.h"
#include "items/pill.h"
#include "items/cigarette.h"
#include "items/beer.h"
#include "items/adrenaline.h"
#include "items/magnifier.h"
#include "items/handcuffs.h"
#include "items/inverter.h"
#include "items/saw.h"
#include "items/phone.h"

class Player;
class Shotgun;

class Session {
private:
    Player dealer, player;
    Player* object;
    Player* subject;
    Shotgun shotgun;
public:
    void config();
    void start();

    void giveTurn(Player& subject);

    void setDealer(Player& dealer);
    void setPlayer(Player& player);

    Player& getDealer();
    Player& getPlayer();
    Player& getObject();
    Player& getSubject();
};

#endif