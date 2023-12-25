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
#include "Actions/MoveFigure.h"
#include "Actions/clearAll.h"
#include "fstream"
#include "Figures/CCircle.h"
#include "to_playmood.h"
#include "figure_type.h"
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include "Actions/playrecord.h"
#include "to_drawmood.h"
#include"Actions/ChangeColorAction.h"
#include"DEFS.h"
#include"Actions/DeleteAction.h"
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include "Actions/playSound.h"
#include "Actions/Action.h"
#include "Actions/RedoAction.h"
#include "CMUgraphicsLib/auxil.h"
#include "to_drawmood.h"
#include "StartandStopRec.h"
#include "Figures/CFigure.h"
int ApplicationManager::countpos = 0;
//int ApplicationManager::countfill = 0;
int ApplicationManager::countrepos = 0;
int ApplicationManager::countbrush = 0;
int ApplicationManager::iX = 0;
int ApplicationManager::iY = 0;

using namespace std;
//class Action ;
//Constructor
ApplicationManager::ApplicationManager() : ActionCountre(0), ActionCountun(0)
{
	//arr_recActions = new Action * [20];
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	DeletedFigCount = 0;
	Selected_Figure = nullptr;
	DeletedFig = nullptr;
	ActionCountun = 0;
	ActionCountre = 0;
	pLastAct = nullptr;
	//Create an array of figure pointers and set them to NULL		

	for (int i = 0; i < MaxFigCount; i++)
	{

		FigList[i] = nullptr;
		DeletedFigList[i] = nullptr;

	}
	for (int i = 0; i < 20; i++)
	{
		arr_recActions[i] = nullptr;
	}
	for (int i = 0; i < 5; i++) {
		ActListun[i] = nullptr;
		ActListre[i] = nullptr;
		fill[i] = UI.BkGrndColor;
		Pos[i] = { 100,100 };
		brush[i] = UI.BkGrndColor;

	}
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

void ApplicationManager::ExecuteAction(ActionType ActType, int numofrec)
{
	Action* pAct = nullptr;
	//playSound(this, ActType);
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

	case DRAW_RECT:
		pAct = new AddRectAction(this);
		addToUndo(pAct);
		break;

	case DRAW_CIRC:

		pAct = new AddcircleAction(this);
		addToUndo(pAct);
		break;

	case DRAW_TRIA:
		pAct = new AddTriangleAction(this);
		addToUndo(pAct);
		break;

	case DRAW_SQUA:
		pAct = new AddSquareAction(this);
		addToUndo(pAct);
		break;

	case DRAW_HEXA:
		pAct = new AddHexaAction(this);
		addToUndo(pAct);
		break;
	case FUNC_SELECT:
		pAct = new SelectAction(this);
		break;
	case ENTER_PLAY_MODE:
		pAct = new to_playmood(this);
		break;
	case BY_SHAPE:
		if (FigCount)
			pAct = new figure_type(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case BY_COLOR:
		if (ChangeColorAction::if_exist_file())
			pAct = new figure_color(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case BY_COLOR_SHAPE:
		if (ChangeColorAction::if_exist_file())
			pAct = new figure_typeandcolor(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case FUNC_FILL:
		//playSound(this, FUNC_FILL);
		pAct = new ChangeColorAction(this, true); addToUndo(pAct);
		break;
	case FUNC_BRUSH:
		//playSound(this, FUNC_BRUSH);
		pAct = new ChangeColorAction(this); addToUndo(pAct);
		break;
	case FUNC_DELETE:
		pAct = new DeleteAction(this);
		addToUndo(pAct);
		break;
	case ENTER_DRAW_MODE:
		pAct = new to_drawmood(this);
		break;
	case FUNC_SAVE:
		pAct = new PrepareExport(this);
		pOut->PrintMessage("SAVE");

		break;

	case FUNC_LOAD:
		pAct = new PrepareImport(this);
		pOut->PrintMessage("LOAD");

		break;

	case FUNC_CLEAR_CANVAS:
		pAct = new clearAll(this);
		pOut->PrintMessage("CLEAR ALL");

		break;

	case FUNC_UNDO:
		pAct = new UndoAction(this);
		pOut->PrintMessage("UNDO");
		break;

	case FUNC_REDO:
		pAct = new RedoAction(this);
		pOut->PrintMessage("REDO");
		break;


	case FUNC_START_REC:
		if (FigCount == 0)
			pAct = new StartandStopRec(this);
		else
			pOut->PrintMessage("can't recording you should delete all");
		break;

	case FUNC_PLAY_REC:
		pAct = new playrecord(this);
		pOut->PrintMessage("PLAY");
		break;

	case FUNC_STOP_REC:
		pOut->PrintMessage("stop");
		break;
	case FUNC_MOVE:

		pAct = new moveFigure(this);
		addToUndo(pAct);
		playSound(this, FUNC_MOVE);
		break;

	case FUNC_EXIT_playMode:
		break;

	case FUNC_EXIT:

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	case DRAWING_AREA:
		if (Selected_Figure != nullptr && Selected_Figure->checkselection(iX, iY)) //a figure must be selected to call a "move by dragging" activity
			pAct = new moveFigure(this, 1);
		break;
	}
	//Execute the created action
	if (numofrec != -1 && pAct != nullptr)
	{

		arr_recActions[numofrec] = pAct;
		pAct->Execute(1);
		pAct = NULL;
	}
	else if (pAct != NULL)
	{
		pIn->FlushMouseQueue();
		//addToUndo(pAct);
		//addToRedo();
		pAct->Execute(1); //Execute
		//ActList[ActionCount++] = pAct;

		pAct = NULL;
	}
}

void ApplicationManager::addfillcolor(color c, int i)
{

	fill[i] = c;

}

void ApplicationManager::addbrushcolor(color c)
{
	brush[countbrush] = c;
	countbrush++;
}


//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
color ApplicationManager::get_indx_fillcolor(int indx)
{
	return fill[indx];
}
color ApplicationManager::get_indx_brushcolor(int indx)
{
	return brush[indx];
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{

	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;

}
void ApplicationManager::AddDeletedFig(CFigure* del)
{
	if (DeletedFigCount < MaxFigCount)
		DeletedFigList[DeletedFigCount++] = del;

}

////////////////////////////////////////////////////////////////////////////////////


void ApplicationManager::Playrecord()
{
	if (arr_recActions[0] != NULL)
	{

		ClearAll();
		Sleep(1000);
		for (int i = 0; i < 20; i++)
		{
			counter++;
			if (arr_recActions[i] == nullptr) break;

			//if(!(dynamic_cast<UndoAction*>(arr_recActions[i])&& dynamic_cast<SelectAction*>(arr_recActions[i])))
			addToUndo(arr_recActions[i]);



			arr_recActions[i]->Execute(0);


			UpdateInterface();

			Sleep(1000);
		}
		pOut->PrintMessage("All recorded actions have been played successfully");
	}
	else
		pOut->PrintMessage("NO ACTIONS RECORDED!!");

}


//Remove a figure from the list of figures
void ApplicationManager::RemoveFigure(CFigure* pFig)
{
	if (FigCount > 0)
		FigList[FigCount--] = nullptr;
}

CFigure* ApplicationManager::DeleteFigure()
{
	CFigure* deletedfigure;
	if (FigCount >= 1)
	{
		deletedfigure = FigList[FigCount - 1];
		FigList[FigCount - 1] = nullptr;
		delete FigList[FigCount - 1];
		FigCount--;
		return deletedfigure;
	}
	else
		return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)                  // Validation to prevent crash if Figure is deleted
		{
			if (FigList[i]->checkselection(x, y))           /// to check whether point is in figure or not
			{
				return FigList[i];

			}


		}

		// if the point dosen't belong to any figure

		pOut->PrintMessage(" No selected figure ");

		//Add your code here to search for a figure given a point x,y
		//Remember that ApplicationManager only calls functions do NOT implement it.


	}pOut->PrintMessage(" No selected figure ");

	return nullptr;

}

void ApplicationManager::setSelectedFigure(CFigure* const sf)
{
	Selected_Figure = sf;
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface()
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if (FigList[i] != NULL)
		{
			FigList[i]->Draw(pOut);
		}          //Call Draw function (virtual member fn)

}

void ApplicationManager::DeleteFunction()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Selected_Figure)
		{
			pOut->ClearStatusBar();
			FigList[i]->SetSelected(false);
			FigList[FigCount] = FigList[i];
			FigList[i] = FigList[FigCount - 1];
			Selected_Figure = NULL;
			FigList[FigCount--] = nullptr;

			break;
		}
	}
}
void ApplicationManager::DeleteFunctionForPlayMood(CFigure* Del)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Del)
		{
			AddDeletedFig(FigList[i]);
			FigList[i] = nullptr;
			UpdateInterface();
			break;
		}
	}
}
void  ApplicationManager::CopyDeletedFigToFiglist()
{
	for (int i = 0; i < DeletedFigCount; i++)
	{
		if (DeletedFigList[i] != nullptr)
		{
			for (int j = 0; j < FigCount; j++)
			{
				if (FigList[j] == nullptr)
				{
					FigList[j] = DeletedFigList[i];
					DeletedFigList[i] = nullptr;
					break;
				}

			}

		}
	}
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


void ApplicationManager::ClearAll()
{

	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
		FigList[i]->clearColor();
		delete FigList[i];
		FigList[i] = nullptr;
	}

	for (int i = 0; i < FigCount; i++)
	{
		delete DeletedFigList[i];
		DeletedFigList[i] = nullptr;
	}

	UpdateInterface();
	FigCount = 0;

	pOut->ClearDrawArea();
	//CFigure:: ID = 0;

}
void ApplicationManager::clear()
{

	for (int i = 0; i < ActionCountun; i++)
	{
		delete ActListun[i];
		ActListun[i] = nullptr;
	}
	for (int i = 0; i < ActionCountre; i++)
	{
		delete ActListre[i];
		ActListre[i] = nullptr;
	}
	for (int i = 0; i < 20; i++)
	{

		arr_recActions[i] = NULL;
		delete arr_recActions[i];
	}
	ActionCountun = 0;
	ActionCountre = 0;
}
void ApplicationManager::addToUndo(Action* pAct)
{

	ActListun[0] = NULL; delete ActListun[0];
	if (ActionCountun > 4) {

		for (int j = 0; j < 4; j++)   //Overwriting Undoarr to make it always have the last five actions 
		{
			ActListun[j] = ActListun[j + 1];
		}
		ActionCountun = 4;
	}
	ActListun[ActionCountun++] = pAct;

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
		pLastAct = ActListun[ActionCountun - 1];
		ActListun[ActionCountun - 1] = NULL;
		delete ActListun[ActionCountun - 1];
		return pLastAct;
	}
	return NULL;
}
CFigure* ApplicationManager::GetLastFigure()
{


	return FigList[FigCount - 1];

}
Action* ApplicationManager::GetLastRedo()
{

	if (ActionCountre >= 1)
	{
		pLastAct = ActListre[ActionCountre - 1];
		ActListre[ActionCountre - 1] = NULL;
		delete ActListre[ActionCountre - 1];
		ActionCountre--;
		return pLastAct;
	}
	return NULL;
}
void ApplicationManager::addPoint(Point p)
{
	Pos[countpos++] = p;
	cout << p;
}

Point ApplicationManager::getpoint(int index)
{
	return Pos[index];
}

void ApplicationManager::addColor(color c)
{
}

void ApplicationManager::getColor()
{
}

//Destructor
ApplicationManager::~ApplicationManager()
{


	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != nullptr) { delete FigList[i]; FigList[i] = nullptr; }
		if (DeletedFigList[i] != nullptr) { delete DeletedFigList[i]; DeletedFigList[i] = nullptr; }
		if (arr_recActions[i] != nullptr) { delete arr_recActions[i]; arr_recActions[i] = nullptr; }
	}
	delete[] arr_recActions;
	delete[] DeletedFigList;
	delete[] FigList;
	delete pIn;
	delete pOut;

}
CFigure* ApplicationManager::GetSelected_Figure()
{
	return Selected_Figure;
}

void  ApplicationManager::SetSelectedFig(CFigure* S)
{
	// case one if there is no selected figure before 

	if (Selected_Figure == NULL)
	{
		Selected_Figure = S;
		Selected_Figure->SetSelected(true);
		Selected_Figure->PrintInfo(pOut);
	}

	// case two if selected figure is seclected before make it unselected and return NUL

	else if (Selected_Figure == S)
	{
		Selected_Figure->SetSelected(false);
		Selected_Figure = NULL;
	}

	//  case 3 if the seleced figure isn't the selected before

	else            //if (Selected_Figure != FigList[i])            
	{
		Selected_Figure->SetSelected(false);
		Selected_Figure = S;
		Selected_Figure->SetSelected(true);
		Selected_Figure->PrintInfo(pOut);
	}


}

void ApplicationManager::set_figure(CFigure* fig)
{
	Selected_Figure = fig;
}

/*
*
*   CFigure* ApplicationManager::GetFigure(int x, int y)
	{
	  for (int i = 0; i < FigCount; i++)
	{
		  if (FigList[i] != NULL)                  // Validation to prevent crash if Figure is deleted
	  {
			  if (FigList[i]->checkselection(x, y))           /// to check whether point is in figure or not
			  {
				  // case one if there is no selected figure before

				  if (Selected_Figure == NULL)
				  {
					  Selected_Figure = FigList[i];
					  Selected_Figure->SetSelected(true);
					  Selected_Figure->PrintInfo(pOut);
					  return Selected_Figure;
				  }

				  // case two if selected figure is seclected before make it unselected and return NUL

				  else if (Selected_Figure == FigList[i])
				  {
					  Selected_Figure->SetSelected(false);
					  Selected_Figure = NULL;
					  return NULL;
				  }

					//  case 3 if the seleced figure isn't the selected before

				  else            //if (Selected_Figure != FigList[i])
				  {
					  Selected_Figure->SetSelected(false);
					  Selected_Figure = FigList[i];
					  Selected_Figure->SetSelected(true);
					  Selected_Figure->PrintInfo(pOut);
					  return Selected_Figure;
				  }


			  }

		  }


	}

					// if the point dosen't belong to any figure

	  pOut->PrintMessage(" No selected figure ");

	  //Add your code here to search for a figure given a point x,y
	//	//Remember that ApplicationManager only calls functions do NOT implement it.
	//
	  return NULL;
	}
*/







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
int ApplicationManager::get_numofcolor(color c)
{
	int num = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->get_fillcolor() == c)
			num++;
	}
	return num;
}
int ApplicationManager::numof_figurewithcolor(figures fig, colors c)
{

	CFigure* check_fig;
	int n = 0;
	switch (fig)
	{
	case squr:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CSquare*>(FigList[i]))
				if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					n++;
		}
		break;
	case rect:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CRectangle*>(FigList[i]))
				if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					n++;
		}
		break;
	case circ:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CCircle*>(FigList[i]))
				if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					n++;
		}
		break;
	case tria:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CTriangle*>(FigList[i]))
				if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					n++;
		}
		break;
	case hexa:
		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CHexa*>(FigList[i]))
				if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					n++;
		}
		break;
	default:
		break;
	}
	return n;
}
color ApplicationManager::get_fillcolor(colors c)
{
	switch (c)
	{
	case black:
		return BLACK;
	case red:
		return RED;
	case blue:
		return BLUE;
	case green:
		return GREEN;
	case yellow:
		return YELLOW;
	case orange:
		return ORANGE;
	default:
		break;
	}
}
string ApplicationManager::color_TO_String(colors c)
{
	switch (c)
	{
	case black:
		return "black";
	case red:
		return "red";
	case blue:
		return "blue";
	case green:
		return "green";
	case yellow:
		return "yellow";
	case orange:
		return "orang";
	default:
		break;
	}
}
string ApplicationManager::figur_TO_String(figures fig)
{
	switch (fig)
	{
	case squr:
		return "square";
	case rect:
		return "rectangle";
	case circ:
		return "circle";
	case tria:
		return "triangle";
	case hexa:
		return "hexagine";
	default:
		break;
	}
}





