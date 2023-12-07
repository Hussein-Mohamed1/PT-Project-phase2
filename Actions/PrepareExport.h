#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class PrepareExport :
    public Action
{
public:
    PrepareExport(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();

};

