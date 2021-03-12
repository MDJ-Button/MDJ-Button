#include "UI.h"
#include "Net.h"

#include <windows.h>

bool RunWithNet()
{
    bool _RunWithNet = false;

    return _RunWithNet;
}

int main()
{
    if(RunWithNet())
    {
        Net net;

        if(net.CheckConnection() == "ScriptMissing")
        {
            MessageBoxA(NULL,"CheckConnection.py is either damaged or missing. Please contact the developer - mdjbutton@gmail.com","File Missing",MB_OK);
        }

        else if(net.CheckConnection() == "have_connection")
        {
            UI ui;

            ui.MainWindow(800, 600, "MDJ Web Extractor 2");
        }

        else if(net.CheckConnection() == "no_connection")
        {
            MessageBoxA(NULL,"The connection has timed out. Please check the network connection and try again.","Connection Timed Out",MB_OK);
        }

        else MessageBoxA(NULL,"Failed on First Step- Could not initialize application. Please contact the developer - mdjbutton@gmail.com","Initialization Error",MB_OK);
    }

    else
    {
        MessageBoxA(NULL,"NOTE - Starting up without internet.","NOTE",MB_OK);

        UI ui;

        ui.MainWindow(800, 600, "MDJ Web Extractor 2");
    }
    return 0;
}
