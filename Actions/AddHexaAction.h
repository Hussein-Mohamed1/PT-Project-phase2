#pragma once
#include "Action.h"
#include "AddHexaAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CHexa.h"
class AddHexaAction :
    public Action
{
private:
    Point P1;
    GfxInfo HexaGfxInfo;
    CFigure* DeletedFig;
    static int numofshapes;
    CHexa* H;
public :
    AddHexaAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute(bool b);

   void undo();
    void redo();
    static int getnumofshapes();

};

