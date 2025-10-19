#include "myFrame.h"
#include "session.h"
#include "aiManager.h"

class Main : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(Main);

bool Main::OnInit() {
    Session* session = new Session;
    AIManager* aiManagerPlayer = new AIManager;
    AIManager* aiManagerDealer = new AIManager;
    session->getDealer().setAIManager(*aiManagerPlayer);
    session->getPlayer().setAIManager(*aiManagerDealer);
    session->getDealer().setIsAI(true);
    session->getPlayer().setIsAI(true);
    session->config();
    MyFrame* myFrame = new MyFrame(*session);
    session->setMyFrame(*myFrame);
    session->getDealer().setMyFrame(*myFrame);
    session->getPlayer().setMyFrame(*myFrame);
    session->displayShotgunMagazineContents();
    myFrame->Show(true);
    return true;
}