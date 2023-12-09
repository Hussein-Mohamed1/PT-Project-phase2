#pragma once
#include "Action.h"
#include"../Actions/SelectAction.h"
#include"../Figures/CFigure.h"
class ChangecolorAction :  public Action
{
private:
    CFigure* Selected_Figure;
    color F_COLOR;
public:
    ChangecolorAction(ApplicationManager* pApp, color C);

    void  ReadActionParameters();

    void Execute();




};

