#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo RectGfxInfo;
    static int numofshapes;
public :
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute();
    static int getnumofshapes();

};

