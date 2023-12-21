#pragma once
#include"../Figures/CFigure.h"
#include "Action.h"
class SelectAction :
    public Action
{
	CFigure* ClickedFigure;
private:
	Point p;
public:
	SelectAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	virtual void undo();
	virtual void redo();


};

