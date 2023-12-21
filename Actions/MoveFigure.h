#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class moveFigure : public Action
{
	Point newPos;
public:
	moveFigure(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();

};