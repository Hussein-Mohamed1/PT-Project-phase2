#pragma once
#include "Action.h"
#include "..\DefS.h"

//Add circle Action class

class AddcircleAction : public Action
{
  private : 
    Point P1, P2;
    GfxInfo RectGfxInfo;
	static int numofshapes;
	CFigure* DeletedFig;
public:
	AddcircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	static int getnumofshapes();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};



