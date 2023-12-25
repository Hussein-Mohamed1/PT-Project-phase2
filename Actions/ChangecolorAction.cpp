#include "ChangeColorAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"


ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, bool CF) :Action(pApp)
{
	ChangeFill = CF;
	ChoosenColor = UI.BkGrndColor;
}
int ChangeColorAction::num_of_fill = 0;
int ChangeColorAction::countfill= 0;
int ChangeColorAction::if_exist_file()
{
	return num_of_fill;
}
void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	f = pManager->GetSelected_Figure();


		pOut->PrintMessage("Choose  Color : ");
		ActionType ActType;
		
		 ActType = pIn->GetUserAction();
		switch (ActType)
		{
		case COLOR_BLACK:
			ChoosenColor = BLACK;
			break;
		case COLOR_RED:
			ChoosenColor = RED;
			break;
		case COLOR_BLUE:
			ChoosenColor = BLUE;
			break;
		case COLOR_GREEN:
			ChoosenColor = GREEN;
			break;
		case COLOR_YELLOW:
			ChoosenColor = YELLOW;
			break;
		case COLOR_ORANGE:
			ChoosenColor = ORANGE;
			break;
		default:
			break;
		}
	

}
void ChangeColorAction::Execute(bool b)
{
	Output* pOut = pManager->GetOutput();
		
		if (b)
	     ReadActionParameters();

		f = pManager->GetSelected_Figure();
		

	//	pManager->AddDeletedFig(pManager->GetSelected_Figure());

	//	pManager->CopyDeletedFigToFiglist();

	if (pManager->GetSelected_Figure() == NULL)

		pOut->PrintMessage("NO SELECTED ");
	else if (ChoosenColor == UI.BkGrndColor)
		pOut->PrintMessage("NO SELECTED COLOR  ");

	else
	{


		if (ChangeFill)
		{
			
			CFigure::IsAllNewFilled(true);
			pOut->SetFillColor(ChoosenColor);
	      
			pManager->addfillcolor(ChoosenColor, countfill); 
			countfill++;
		    num_of_fill++;
			f->ChngFillClr(ChoosenColor);
		
		}

		else
		{
			//pManager->GetSelected_Figure()->ChngFillClr(BLACK);
			f->ChngDrawClr(ChoosenColor);
			pOut->SetDraColor(ChoosenColor);
			pManager->addbrushcolor(ChoosenColor);
		}



	}
}

void ChangeColorAction::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}

void ChangeColorAction::undo()

{
	
	
				if (countfill <= 1)
	{


		f->ChngFillClr(UI.BkGrndColor);
	}

	else

		if (ChangeFill)
	{
				countfill--;
		f->ChngFillClr(pManager->get_indx_fillcolor(countfill - 1));	
	
	}
	else {
		ApplicationManager::countbrush--;
		f->ChngDrawClr(pManager->get_indx_brushcolor(ApplicationManager::countbrush));
	}
}


void ChangeColorAction::redo()
{
	if (ChangeFill)
	{
     
		countfill = 0;
		f->ChngFillClr(pManager->get_indx_fillcolor(countfill + 1)); countfill++;
	}
	else {
		ApplicationManager::countbrush++;
		f->ChngDrawClr(pManager->get_indx_brushcolor(ApplicationManager::countbrush));


	}
}

