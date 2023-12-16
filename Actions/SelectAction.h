#pragma once
#include"../Figures/CFigure.h"
#include "Action.h"
class SelectAction :
    public Action
{
private:
	Point p;
public:
	SelectAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();

};

