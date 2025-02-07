#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "myFrame.h"

class Main : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(Main);

bool Main::OnInit() {
    MyFrame* myFrame = new MyFrame;
    myFrame->Show(true);
    return true;
}