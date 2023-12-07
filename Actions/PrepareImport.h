#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class PrepareImport :
    public Action
{
public:
    PrepareImport(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();

};

