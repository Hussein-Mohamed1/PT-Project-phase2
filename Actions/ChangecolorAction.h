#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{
    bool ChangeFill;
    color  ChoosenColor;
public:

    ChangeColorAction(ApplicationManager* pApp,bool CF=0);

    virtual void ReadActionParameters();

    virtual void Execute();

};

