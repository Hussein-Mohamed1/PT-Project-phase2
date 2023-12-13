#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{
    color C;
public:
    ChangeColorAction(ApplicationManager* pApp,color c);

    virtual void ReadActionParameters();

    virtual void Execute();

};

