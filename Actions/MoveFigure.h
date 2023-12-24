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
	bool byDragging;
public:
	moveFigure(ApplicationManager* pApp,bool byDragging =0);
	void ReadActionParameters();
	bool move();
	void moveByDragging();
	void Execute(bool b);
	 void undo();
	 void redo();
};