#pragma once
#include "Action.h"
class ChangeColorAction :
    public Action
{
    color DrawColor;
    color FillColor;
    bool ChangeFill;
    static int num_of_fill;
public:

    ChangeColorAction(ApplicationManager* pApp, color c,bool CF=0);

    virtual void ReadActionParameters();
  static  int if_exist_file();
    virtual void Execute();

};

