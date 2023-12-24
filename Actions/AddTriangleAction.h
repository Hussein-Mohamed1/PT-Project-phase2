#pragma once
#include "Action.h"
class AddTriangleAction :
    public Action
{
private :
    Point P1, P2, P3;
    GfxInfo RectGfxInfo;
    CFigure* DeletedFig;
    static int numofshapes;
public :
    AddTriangleAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

   void Execute(bool b) ;
   void undo();
     void redo();
    static int getnumofshapes();

};

