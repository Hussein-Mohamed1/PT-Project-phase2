#pragma once
#include "Action.h"
class AddTriangleAction :
    public Action
{
private :
    Point P1, P2, P3;
    GfxInfo RectGfxInfo;
    
public :
    static int numoftria;
    AddTriangleAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute() ;


};

