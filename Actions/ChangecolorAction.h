#pragma once
#include "Action.h"
//#include "color.h"
class ChangeColorAction :
	public Action
{
    bool ChangeFill;
    color  ChoosenColor;
    int counter;
    CFigure* f;
    static int  num_of_fill;


public:
    ChangeColorAction(ApplicationManager* pApp,bool CF=0);
  static int countfill;
    virtual void ReadActionParameters();
  static  int if_exist_file();
    void Execute(bool b);
  void addundofirst(Action* pAct);
    void undo();
     void redo();
   static  void decrement_fill();
   static void resetnumoffill();
};

