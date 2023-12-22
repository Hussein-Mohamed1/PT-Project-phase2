#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class PrepareImport :
    public Action
{
    string name;
public:
    PrepareImport(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();
    virtual void undo();
    virtual void redo();
};

