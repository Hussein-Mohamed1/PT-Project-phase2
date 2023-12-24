#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo HexaGfxInfo;
    CFigure* DeletedFig;
    static int numofshapes;
public :
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute(bool b);

   void undo();
    void redo();
    static int getnumofshapes();

};

