#include "ChangeColorAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"


ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, bool CF) :Action(pApp)
{
	ChangeFill = CF;
	ChoosenColor = WHITE;



}
int ChangeColorAction::num_of_fill = 0;

int ChangeColorAction::if_exist_file()
{
	return num_of_fill;
}
void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose  Color : ");
	ActionType ActType;
	int x, y;
	ActType = pIn->GetUserAction(x, y);
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

	//	pManager->AddDeletedFig(pManager->GetSelected_Figure());

	//	pManager->CopyDeletedFigToFiglist();

	if (pManager->GetSelected_Figure() == NULL)

		pOut->PrintMessage("NO SELECTED ");
	else if (ChoosenColor == WHITE)
		pOut->PrintMessage("NO SELECTED COLOR  ");

	else
	{


		if (ChangeFill)
		{
			num_of_fill++;
			pManager->GetSelected_Figure()->ChngFillClr(ChoosenColor);
			CFigure::IsAllNewFilled(true);
			pOut->SetFillColor(ChoosenColor);
			pManager->addfillcolor(ChoosenColor);

		}

		else
		{
			//pManager->GetSelected_Figure()->ChngFillClr(BLACK);
			pManager->GetSelected_Figure()->ChngDrawClr(ChoosenColor);
			pOut->SetDraColor(ChoosenColor);
			pManager->addbrushcolor(ChoosenColor);
		}



	}
}

void ChangeColorAction::undo()

{
	if (ApplicationManager::countfill <= 1)
	{


		pManager->GetLastFigure()->ChngFillClr(UI.BkGrndColor);
	}

	else if (ChangeFill)
	{

		ApplicationManager::countfill--;

		pManager->GetLastFigure()->ChngFillClr(pManager->get_indx_fillcolor(ApplicationManager::countfill - 1));
	}
	else {
		ApplicationManager::countbrush--;
		pManager->GetLastFigure()->ChngDrawClr(pManager->get_indx_brushcolor(ApplicationManager::countbrush));
	}
}


void ChangeColorAction::redo()
{
	if (ChangeFill)
	{

		ApplicationManager::countfill++;
		pManager->GetLastFigure()->ChngFillClr(pManager->get_indx_fillcolor(ApplicationManager::countfill - 1));
	}
	else {
		ApplicationManager::countbrush++;
		pManager->GetLastFigure()->ChngDrawClr(pManager->get_indx_brushcolor(ApplicationManager::countbrush));


	}
}

