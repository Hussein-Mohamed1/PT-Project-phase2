#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddcircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions/AddSquareAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/SelectAction.h"
#include "Actions/PrepareExport.h"
#include "Actions/PrepareImport.h"
#include "Actions/UndoAction.h"
#include "fstream"
#include "Figures/CCircle.h"
#include "Actions/Action.h"
#include "Actions/RedoAction.h"
using namespace std;
//class Action ;
//Constructor
ApplicationManager::ApplicationManager()
{

	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	 ActionCountun = 0;
	 ActionCountre = 0;
	 pLastAct = nullptr;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 0; i < maxActionCount; i++)
		ActListun[i] = NULL;
	for (int i = 0; i < maxActionCount; i++)
		ActListre[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
	{pAct = new AddRectAction(this);
	addToUndo(pAct);

}
	break;

	case DRAW_CIRC:
	{
		pAct = new AddcircleAction(this);
		addToUndo(pAct);
		
	}
		break;

	case DRAW_TRIA:
	{pAct = new AddTriangleAction(this);
	addToUndo(pAct);
	
	}
		break;

	case DRAW_SQUA:
	{	pAct = new AddSquareAction(this);
	addToUndo(pAct);
	
	}
	
		break;

	case DRAW_HEXA:
	{
		pAct = new AddHexaAction(this);
		addToUndo(pAct);
		
	}
		break;
	case FUNC_SELECT:
		pAct = new SelectAction(this);
		break;
	case FUNC_SAVE:
		pAct = new PrepareExport(this);
		break;
	case FUNC_LOAD:
		pAct = new PrepareImport(this);
		break;
	case FUNC_UNDO:
		pAct = new UndoAction(this);
			break;

	case FUNC_REDO:
		pAct = new RedoAction (this);
		break;
	case FUNC_EXIT:
		///create ExitAction 
		break;
		
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		//addToUndo(pAct);
		//addToRedo();
		pAct->Execute(); //Execute
		//ActList[ActionCount++] = pAct;
	//	delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}


//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
//Remove a figure from the list of figures
void ApplicationManager::RemoveFigure(CFigure* pFig)
{
	if (FigCount >0)
		FigList[FigCount--] = nullptr;
}

CFigure* ApplicationManager::DeleteFigure()
{
	CFigure* deletedfigure;
	if (FigCount >= 1)
	{
		deletedfigure = FigList[FigCount-1];
		FigList [FigCount-1] = nullptr;
		delete FigList[FigCount-1];
		FigCount--;
		return deletedfigure;
	}
	else 
	return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	// 
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->checkselection(x, y))
		{
			if (FigList[i]->IsSelected())                 /// check any figure is selected
			{
				FigList[i]->SetSelected(false);          // case selected before  un select it
			}
		    else FigList[i]->SetSelected(true);          // case unselected before select it

			int k = 0;
			while (k != FigCount)                       // to validate multiply selection 
			{
				if (FigList[k] != FigList[i])
				{
					FigList[k]->SetSelected(false);
				}
				k++;
			}

			return FigList[i];
		}

	
	}

	pOut->PrintMessage(" No Selected Figure , To Select Figure Click on select icon agian ");
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.


	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{

	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if (FigList[i] != NULL)
		{
			FigList[i]->Draw(pOut);
		}          //Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
// Makes Each Figure save its data
void ApplicationManager::SaveAll(fstream& OutputFile) const {
	if (OutputFile.good()) {
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i] != nullptr)
				FigList[i]->Save(OutputFile);
		}
		OutputFile.close();
	}
}

void ApplicationManager::addToUndo(Action* pAct)
{
	if (ActionCountun < 5&& ActionCountun>=0)
	{
		ActListun[ActionCountun] = pAct;

		//if (ActionCountun < 4)
		ActionCountun++;
		
	}else
	{
		ActionCountun = 5;

		for (int i = 0;i < ActionCountun;i++) {//Shifting Actions
			Action* temp1 = ActListun[i];
			ActListun[i] = pAct;
			pAct = temp1;
		}
	}
}

void ApplicationManager::addToRedo()
{
	ActListre[ActionCountre] = pLastAct;
	ActionCountun--;
	ActionCountre++;

}

Action* ApplicationManager::GetLastUndo()
{
	if (ActionCountun >= 1)
	{
		pLastAct = ActListun[ActionCountun-1];
		ActListun[ActionCountun-1] = NULL;
		delete ActListun[ActionCountun-1 ];
		return pLastAct;
	}
	return NULL;
}
Action* ApplicationManager::GetLastRedo()
{
	if (ActionCountre >= 1)
	{
		pLastAct = ActListre[ActionCountre - 1];
		ActListre[ActionCountre-1] = NULL;
		delete ActListre[ActionCountre - 1];
		ActionCountre--;
		return pLastAct;
	}
	return NULL;
}
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}

