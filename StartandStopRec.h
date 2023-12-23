#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class StartandStopRec : public Action
{
	ActionType current_action;
	bool stop_rec=false;
	Action** arr_Actions;
public :
	StartandStopRec(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~StartandStopRec();
};

