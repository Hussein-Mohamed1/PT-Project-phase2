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
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include"to_playmood.h"
#include "Actions/playSound.h"
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
	DeletedFigCount = 0;
	Selected_Figure = NULL;
	ActionCountun = 0;
	ActionCountre = 0;
	pLastAct = nullptr;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		DeletedFigList[i] = nullptr;
	}
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
	Action* pAct = nullptr;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		playSound(this, DRAW_RECT);
		addToUndo(pAct);
		break;

	case DRAW_CIRC:

		pAct = new AddcircleAction(this);
		playSound(this, DRAW_CIRC);
		addToUndo(pAct);
		break;

	case DRAW_TRIA:
		pAct = new AddTriangleAction(this);
		playSound(this, DRAW_TRIA);
		addToUndo(pAct);
		break;

	case DRAW_SQUA:
		pAct = new AddSquareAction(this);
		playSound(this, DRAW_SQUA);
		addToUndo(pAct);
		break;

	case DRAW_HEXA:
		pAct = new AddHexaAction(this);
		playSound(this, DRAW_HEXA);
		addToUndo(pAct);
		break;
	case FUNC_SELECT:
		pAct = new SelectAction(this);
		playSound(this, FUNC_SELECT);
		break;
	case ENTER_PLAY_MODE:
		pAct = new to_playmood(this);
		playSound(this, ENTER_PLAY_MODE);
		break;
	case BY_SHAPE:
		pAct = new figure_type(this);
		break;
	case BY_COLOR:
		pAct = new figure_color(this);
		break;
	case BY_COLOR_SHAPE:
		pAct = new figure_typeandcolor(this);
		break;
	case FUNC_FILL:
		pAct = new ChangeColorAction(this, true);
		playSound(this, FUNC_FILL);
		break;
	case FUNC_BRUSH:
		pAct = new ChangeColorAction(this);
		playSound(this, FUNC_BRUSH);
		break;
	case FUNC_DELETE:
		pAct = new DeleteAction(this);
		break;
	case ENTER_DRAW_MODE:
		pAct = new to_drawmood(this);
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
		pAct = new RedoAction(this);
		break;
		pOut->PrintMessage("START");
		break;
	case FUNC_PLAY_REC:
		pOut->PrintMessage("PLAY");
		break;
	case FUNC_STOP_REC:
		pOut->PrintMessage("stop");
		break;
	case FUNC_MOVE:
		pAct = new moveFigure(this);
		playSound(this, FUNC_MOVE);
		break;
	case FUNC_EXIT_playMode:
		break;

	case FUNC_EXIT:
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
void ApplicationManager::AddDeletedFig(CFigure* del)
{
	if (DeletedFigCount < MaxFigCount)
		DeletedFigList[DeletedFigCount++] = del;

}

////////////////////////////////////////////////////////////////////////////////////
//Remove a figure from the list of figures{
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


	}

	// if the point dosen't belong to any figure

	pOut->PrintMessage(" No selected figure ");

	//Add your code here to search for a figure given a point x,y
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
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
			//Selected_Figure->SetSelected(false);             
		   //		pOut->ClearDrawArea();                 
			pOut->ClearStatusBar();
			delete FigList[i];
			FigList[i] = NULL;
			Selected_Figure = NULL;
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
			FigList[i] = NULL;
			UpdateInterface();
			break;
		}
	}
}
void  ApplicationManager::CopyDeletedFigToFiglist()
{
	for (int i = 0; i < DeletedFigCount; i++)
	{
		if (DeletedFigList[i] != NULL)
		{
			for (int j = 0; j < FigCount; j++)
			{
				if (FigList[j] == NULL)
				{
					FigList[j] = DeletedFigList[i];
					DeletedFigList[i] = NULL;
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

void ApplicationManager::addToUndo(Action* pAct)
{
	if (ActionCountun < 5 && ActionCountun >= 0)
	{
		ActListun[ActionCountun] = pAct;

		//if (ActionCountun < 4)
		ActionCountun++;

	}
	else
	{
		ActionCountun = 5;

		for (int i = 0; i < ActionCountun; i++) {//Shifting Actions
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
		pLastAct = ActListun[ActionCountun - 1];
		ActListun[ActionCountun - 1] = NULL;
		delete ActListun[ActionCountun - 1];
		return pLastAct;
	}
	return NULL;
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
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != nullptr) { delete FigList[i]; FigList[i] = nullptr; }
		if (DeletedFigList[i] != nullptr) { delete DeletedFigList[i]; }

	}
	delete pIn;
	delete pOut;

}
CFigure* ApplicationManager::GetSelected_Figure()
{
	return Selected_Figure;
}



void ApplicationManager::set_figure(CFigure* fig)
{
	Selected_Figure = fig;
}

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





