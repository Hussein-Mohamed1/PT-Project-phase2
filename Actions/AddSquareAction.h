#pragma once
#include "Action.h"
#include "..\DefS.h"
class AddSquareAction : public Action
{
private:
	Point P1, P2;
	GfxInfo RectGfxInfo;
	CFigure* DeletedFig;
	static int numofshapes;
public :
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual void redo();
	Point  GetP1();
	Point Getp2();
	static int getnumofshapes();


};

