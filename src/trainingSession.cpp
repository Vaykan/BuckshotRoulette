#include "trainingSession.h"
#include "session.h"

size_t TrainingSession::iterationsLeft = 0;

void TrainingSession::resetGameSession(Session& session) {
    int randomCount = rGetNum(2, 4);
    session.getDealer().setMaxHitPoint(randomCount);
    session.getDealer().setHitPoint(randomCount);
    session.getPlayer().setMaxHitPoint(randomCount);
    session.getPlayer().setHitPoint(randomCount);

    randomCount = rGetNum(1, 4);

    session.getPlayer().getItem().clear();
    session.getDealer().getItem().clear();
    session.getPlayer().addRandomItems(randomCount);
    session.getDealer().addRandomItems(randomCount);

    session.getShotgun().getMagazine().clear();
    session.getShotgun().loading(rGetNum(2, 8));
}
