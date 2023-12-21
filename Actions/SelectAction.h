#pragma once
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
	virtual void undo();
	virtual void redo();


};

