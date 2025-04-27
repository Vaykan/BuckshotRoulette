#ifndef BUCKSHOT_ROULETTE_EXE_MYFRAME_H
#define BUCKSHOT_ROULETTE_EXE_MYFRAME_H

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

#include "session.h"
#include "player.h"

class MyFrame : public wxFrame {
    static constexpr int BUTTON_ITEM = 8;
    Session& session;
    std::array<wxButton*, BUTTON_ITEM> objectItemSlot = {};
    std::array<wxButton*, BUTTON_ITEM> subjectItemSlot = {};
    void updateAllButtonName();

public:
    MyFrame(Session& session);

    void setSession(Session& session);

    void OnAnyButtonClicked(wxCommandEvent& event);
};

#endif