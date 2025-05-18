#ifndef BUCKSHOT_ROULETTE_SESSION_H
#define BUCKSHOT_ROULETTE_SESSION_H

#include "player.h"
#include "shotgun.h"
#include "input.h"
#include "myFrame.h"

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
class MyFrame;

class Session {
private:
    Player dealer, player;
    Player* object;
    Player* subject;
    Shotgun shotgun;

    MyFrame* myFrame = nullptr;
public:
    void config();
    void start();

    void shootTarget();
    void shootYourself();


    void giveTurn(Player& subject);

    void checkTurn();
    void swapTurn();

    void setDealer(Player& dealer);
    void setPlayer(Player& player);

    Player& getDealer();
    Player& getPlayer();
    Player& getObject();
    Player& getSubject();

    void setMyFrame(MyFrame& myFrame);
    MyFrame* getMyFrame();

    ShellType getPreviousShellType();

    void displayShotgunMagazineContents();
};

#endif