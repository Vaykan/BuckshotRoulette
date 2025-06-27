#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "myFrame.h"
#include "session.h"

class Main : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(Main);

bool Main::OnInit() {
    Session* session = new Session;
    session->config();
    MyFrame* myFrame = new MyFrame(*session);
    session->setMyFrame(*myFrame);
    session->getDealer().setMyFrame(*myFrame);
    session->getPlayer().setMyFrame(*myFrame);
    session->displayShotgunMagazineContents();
    myFrame->Show(true);
    return true;
}