#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo RectGfxInfo;
    CFigure* DeletedFig;
public :
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute();

    virtual void undo();
    virtual void redo();
};

