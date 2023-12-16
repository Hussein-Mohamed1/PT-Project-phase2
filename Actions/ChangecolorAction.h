#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{
    color DrawColor;
    color FillColor;
    bool ChangeFill;
       
public:

    ChangeColorAction(ApplicationManager* pApp, color c,bool CF=0);

    virtual void ReadActionParameters();

    virtual void Execute();

};

