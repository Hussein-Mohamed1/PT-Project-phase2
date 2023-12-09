#pragma once
#include"../Figures/CFigure.h"
#include "Action.h"
class SelectAction :
    public Action
{
private:
	Point p;
	static CFigure* Selected_Figure;
public:
	SelectAction(ApplicationManager* pApp);
    static CFigure* GetSelected_Figure();
	void ReadActionParameters();
	void Execute();

};

