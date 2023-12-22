#pragma once
#pragma once
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include "Action.h"
#include "..\ApplicationManager.h"
#include "AddRectAction.h"
#include"AddcircleAction.h"
#include"AddTriangleAction.h"
#include"AddSquareAction.h"
#include"AddHexaAction.h"
#include"SelectAction.h"
#include "PrepareExport.h"
#include "PrepareImport.h"
#include "UndoAction.h"
#include "fstream"
#include "..\Figures/CCircle.h"
class UndoAction : public Action
{
	
	
public:

	UndoAction(ApplicationManager* pApp) ;
	

	
	 virtual void Execute() ;
	 virtual void ReadActionParameters();
	 virtual void undo();
	 virtual void redo();

};