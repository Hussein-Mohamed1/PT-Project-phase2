#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddcircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions/AddSquareAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/SelectAction.h"
#include "Actions/PrepareExport.h"
#include "Actions/PrepareImport.h"
#include "fstream"
#include "Figures/CCircle.h"
#include "to_playmood.h"
#include "figure_type.h"
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include "to_drawmood.h"
#include"Actions/ChangeColorAction.h"
#include"DEFS.h"
#include"Actions/DeleteAction.h"


using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	Selected_Figure = NULL;


	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
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
		pAct = new AddRectAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddcircleAction(this);
		break;
	case DRAW_TRIA:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_SQUA:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_HEXA:
		pAct = new AddHexaAction(this);
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
	case ENTER_PLAY_MODE:
		pAct = new to_playmood(this);
		break;
	case BY_SHAPE:
		pAct = new figure_type(this);
		break;
	case COLOR_BLACK:
	pAct = new ChangeColorAction(this,BLACK);
		break;
	case COLOR_RED:
	pAct = new ChangeColorAction(this,RED);
		break;
	case COLOR_GREEN :
		pAct = new ChangeColorAction(this, GREEN);
		break;
	case COLOR_ORANGE:
		pAct = new ChangeColorAction(this, ORANGE);
		break;
	case COLOR_YELLOW:
		pAct = new ChangeColorAction(this, YELLOW);
		break;
	case COLOR_BLUE:
		pAct = new ChangeColorAction(this, BLUE);
		break;
	case FUNC_FILL:
		pAct = new ChangeColorAction(this,BLUE,1);
		break;
	case FUNC_DELETE :
		pAct = new DeleteAction(this);
		break;




	case FUNC_EXIT_playMode:

	case FUNC_EXIT:
		///create ExitAction here
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
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
CFigure* ApplicationManager::GetFigure(int x, int y) 
{
	for (int i = 0; i < FigCount; i++)
{  
	if (FigList[i]->checkselection(x, y))    
	{  
     	if (Selected_Figure == NULL)
     	{
		Selected_Figure = FigList[i];
		Selected_Figure->SetSelected(true);
		return Selected_Figure;
	     }
      	else if (Selected_Figure == FigList[i])
      	{
		Selected_Figure->SetSelected(false);
		Selected_Figure = NULL;
		return NULL;
	    }
	       else            //if (Selected_Figure != FigList[i])
	    {
		Selected_Figure->SetSelected(false);
		Selected_Figure = FigList[i];
		Selected_Figure->SetSelected(true);
		return Selected_Figure;
		}


    } 


	
}

	pOut->PrintMessage(" No selected figure ");
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

//bool ApplicationManager :: Select(CFigure* figure)
//{
//	if (Selected_Figure==figure) {
//		Selected_Figure->SetSelected(false);
//		Selected_Figure = nullptr;
//	}
//	else if (Selected_Figure == nullptr)
//	{
//		Selected_Figure = figure;
//		Selected_Figure->SetSelected(true);
//	}
//	else  //if (Selected_Figure != figure)
//	{
//		Selected_Figure->SetSelected(false);
//		Selected_Figure = nullptr;
//		Selected_Figure = figure;
//		Selected_Figure->SetSelected(true);
//
//	}
//
//}
//
//CFigure* ApplicationManager:: GetFigureByPoint(int x, int y)
//{
//	for (int i = 0; i < FigCount; i++)
//	{
//		if (FigList[i]->checkselection(x, y))
//		{
//			return FigList[i];
//		}
//	}
//}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			FigList[i]->Draw(pOut);	//Call Draw function (virtual member fn)
		}
	}
}
void ApplicationManager::DeleteFunction()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Selected_Figure)
		{
			Selected_Figure->SetSelected(false);
			FigList[i] == NULL;
			Selected_Figure = NULL;
			break;

		}
	}
}

//void ApplicationManager:: DeleteFigure(CFigure* Del)
//{
//	for (int i = 0; i < FigCount; i++)
//	{
//		if (FigList[i] == Del)
//			FigList[i] = nullptr;
//	}
//	
//
//}
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

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
  CFigure* ApplicationManager::GetSelected_Figure() 
{
	return Selected_Figure;
}








			//if (FigList[i]->IsSelected())                 /// check any figure is selected
			//{
			//	FigList[i]->SetSelected(false);          // case selected before  un select it
			//	return NULL;
			//}
			//else                                         // case unselected before select it
			//{
			//	FigList[i]->SetSelected(true);
			//}

			//int k = 0;
			//while (k != FigCount)                       // to validate multiply selection 
			//{
			//	if (FigList[k] != FigList[i])
			//	{
			//		FigList[k]->SetSelected(false);
			//	}
			//	k++;
			//}

			//return FigList[i];
