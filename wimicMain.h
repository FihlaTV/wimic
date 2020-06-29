
#ifndef WIMICMAIN_H
#define WIMICMAIN_H

#include <wx/taskbar.h>
#include <wx/xrc/xmlres.h>

//(*Headers(wimicDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
#include <wx/hyperlink.h>
#include <wx/led.h>
#include <wx/listbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

class wimicDialog: public wxDialog
{
    public:

        wimicDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~wimicDialog();

    private:

        static bool _started;
        static bool _server_started;

        static void *_main_start(void *arg);
        static void *_server_main_start(void *arg);
        void _start_server();
        void _start_client();
        void _make_dir(const char *dir, int perm);
        void _detect_devices();
        const char *_get_local_ip();
        void _make_about();

        //(*Handlers(wimicDialog)
        void OnQuit(wxCommandEvent& event);
        void Onstart_clientClick(wxCommandEvent& event);
        void Onstop_clientClick(wxCommandEvent& event);
        void Ontimer_connect_statusTrigger(wxTimerEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnKillFocus(wxFocusEvent& event);
        void OnPanel1KillFocus(wxFocusEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wimicDialog)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT1;
        static const long ID_LED1;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_PANEL1;
        static const long ID_TEXTCTRL1;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(wimicDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxBoxSizer* BoxSizer3;
        wxBoxSizer* BoxSizer4;
        wxBoxSizer* BoxSizer5;
        wxBoxSizer* BoxSizer6;
        wxBoxSizer* BoxSizer7;
        wxBoxSizer* BoxSizer8;
        wxButton* close;
        wxButton* select_dev;
        wxButton* start_client;
        wxButton* stop_server;
        wxFlexGridSizer* FlexGridSizer1;
        wxGridBagSizer* GridBagSizer1;
        wxHyperlinkCtrl* hyper_link_license;
        wxLed* Led1;
        wxListBox* ListBox1;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* about_panel;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* dev_label_sel;
        wxStaticText* lblstatconnection;
        wxStaticText* local_ip_label;
        wxTextCtrl* text_about;
        wxTimer timer_connect_status;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WIMICMAIN_H
