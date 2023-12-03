#pragma once
#include "Action.h"
#include "..\DefS.h"
class AddSquareAction : public Action
{
private:
	Point P1, P2;
	GfxInfo RectGfxInfo;
public :
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();



};

