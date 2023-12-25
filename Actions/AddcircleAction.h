#pragma once
#include "Action.h"
#include "..\DefS.h"
#include "..\Figures\CCircle.h"
//Add circle Action class

class AddcircleAction : public Action
{
  private : 
    Point P1, P2;
    GfxInfo CircleGfxInfo;
	static int numofshapes;
	CCircle* c;
	CFigure* DeletedFig;
public:
	AddcircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	static int getnumofshapes();
	//Add rectangle to the ApplicationManager
 void Execute(bool b);
	 void undo();
	void redo();
};



