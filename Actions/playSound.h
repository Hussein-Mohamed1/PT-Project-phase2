#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class playSound :public Action {
	ActionType act;
public:
	playSound(ApplicationManager * pApp, ActionType act);
	void ReadActionParameters();
	void Execute();
	void undo() {};
	void redo() {};
};