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
    wxButton* shootButton = nullptr;
    wxButton* shootYourselfButton = nullptr;
    wxTextCtrl* textCtrl = nullptr;
    wxStaticText* objectHpText = nullptr;
    wxStaticText* subjectHpText = nullptr;
    wxStaticText* objectNameText = nullptr;
    wxStaticText* subjectNameText = nullptr;
    wxButton* debugButton = nullptr;

    void updateHpStaticText();
    void updateNameStaticText();
    void updateAllButtonText();

#ifndef NDEBUG
    bool isDebugButtonActivated = false;
#endif
public:
    MyFrame(Session& session);

    wxTextCtrl* getTextCtrl();

    void OnSubjectItemButtonClicked(wxCommandEvent& event);
    void OnObjectItemButtonClicked(wxCommandEvent& event);
    void OnShootButtonClicked(wxCommandEvent& event);
    void OnShootYourselfButtonClicked(wxCommandEvent& event);
    void OnDebugButtonClicked(wxCommandEvent& event);
};

#endif