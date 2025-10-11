#ifndef BUCKSHOT_ROULETTE_SESSION_H
#define BUCKSHOT_ROULETTE_SESSION_H

#ifndef NDEBUG
#include <windows.h>
#endif

#include "player.h"
#include "shotgun.h"


class Player;
class Shotgun;
class MyFrame;

class Session {
private:
    Player dealer, player;
    Player* object;
    Player* subject;
    Shotgun shotgun;
    Action lastAction;

    MyFrame* myFrame = nullptr;
public:
    void config();

    void checkTurn();
    void swapTurn();

    Player& getDealer();
    Player& getPlayer();
    Player& getObject();
    Player& getSubject();

    void setLastAction(Action lastAction);

    void setMyFrame(MyFrame& myFrame);
    MyFrame* getMyFrame();

    void displayShotgunMagazineContents();

    void shootTarget();
    void shootYourself();


};

#endif