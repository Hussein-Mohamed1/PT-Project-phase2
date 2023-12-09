#pragma once
#include "Action.h"
#include "..\DefS.h"
class AddSquareAction : public Action
{
private:
	Point P1, P2;
	GfxInfo RectGfxInfo;
	
public :
	static int numofsqar;
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();



};

