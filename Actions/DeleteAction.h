#pragma once
#include "Action.h"
#include"../Figures/CFigure.h"
class DeleteAction :  public Action
{
    CFigure* deletedFigure;

public:
    DeleteAction(ApplicationManager* pApp);
    void  ReadActionParameters();
    void Execute();

};

