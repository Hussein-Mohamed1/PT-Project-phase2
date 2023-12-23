#pragma once
#include "Actions/Action.h"
class to_playmood : public Action
{
public :
	to_playmood(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};

