#pragma once
#include "Action.h"
//#include "color.h"
class ChangeColorAction :
    public Action
{
    bool ChangeFill;
    color  ChoosenColor;
    int counter;
    static int num_of_fill;
    CFigure* f;

 

public:

    ChangeColorAction(ApplicationManager* pApp,bool CF=0);

    virtual void ReadActionParameters();
  static  int if_exist_file();
    virtual void Execute();

    virtual void undo();
    virtual void redo();
};

