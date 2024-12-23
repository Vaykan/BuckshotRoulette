#include "session.h"


void Session::setDealer(Player &dealer) {
    this->dealer = dealer;
}

void Session::setPlayer(Player &player) {
    this->player = dealer;
}

void Session::start() {
    dealer.setTarget(player);
    dealer.setShotgun(shotgun);

    player.setTarget(dealer);
    player.setShotgun(shotgun);

    Player* object;
    Player* subject;

    object = &dealer;
    subject = &player;

    while (player.getHitPoint() && dealer.getHitPoint()) {
        giveTurn(*subject);
        if(shotgun.isEmpty()){
            object = &dealer;
            subject = &player;
        } else {
            std::swap(object, subject);
        }
    }
}

void Session::giveTurn(Player &subject) {

}
