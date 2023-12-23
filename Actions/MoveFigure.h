#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class moveFigure : public Action
{
	Point newPos;
	CFigure* DeletedFig;
	Point lastPoint;
	
	CFigure* cFigure;
	CFigure* f;
public:
	moveFigure(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	virtual void undo();
	virtual void redo();

	~moveFigure();
};