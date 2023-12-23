#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo RectGfxInfo;
    CFigure* DeletedFig;
    static int numofshapes;
public :
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute();

    virtual void undo();
    virtual void redo();
    static int getnumofshapes();

};

