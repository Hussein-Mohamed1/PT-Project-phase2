#pragma once
#pragma once
#include"Action.h"
class playrecord :public Action
{

public:
	playrecord(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);

     void undo();
	 void redo();

	~playrecord();
};

