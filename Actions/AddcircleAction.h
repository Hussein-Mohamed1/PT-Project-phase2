#pragma once
#include "Action.h"
#include "..\DefS.h"

//Add circle Action class

class AddcircleAction : public Action
{
  private : 
    Point P1, P2;
    GfxInfo RectGfxInfo;
public:
	AddcircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};



