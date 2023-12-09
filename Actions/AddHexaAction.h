#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo RectGfxInfo;

public :
    static int numofhexa;
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute();


};

