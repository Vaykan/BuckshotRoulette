#ifndef BUCKSHOT_ROULETTE_EXE_MYFRAME_H
#define BUCKSHOT_ROULETTE_EXE_MYFRAME_H

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>

class Session;
class Player;

class MyFrame : public wxFrame {
    static constexpr int BUTTON_ITEM = 8;
    Session* session;

    std::array<wxButton*, BUTTON_ITEM> objectItemSlot = {};
    std::array<wxButton*, BUTTON_ITEM> subjectItemSlot = {};
    wxTextCtrl* textCtrl = nullptr;
    wxStaticText* objectHpText = nullptr;
    wxStaticText* subjectHpText = nullptr;

    void updateHpStaticText();
    void updateAllButtonText();
public:
    MyFrame(Session& session);

    wxTextCtrl* getTextCtrl();

    void OnAnyButtonClicked(wxCommandEvent& event);
};

#endif