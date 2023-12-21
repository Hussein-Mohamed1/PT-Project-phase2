#include "ChangeColorAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


ChangeColorAction::ChangeColorAction(ApplicationManager* pApp,  bool CF):Action(pApp)
{
	ChangeFill = CF;
	ChoosenColor = WHITE;

}
void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

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
void ChangeColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (pManager->GetSelected_Figure() == NULL)
		pOut->PrintMessage("NO SELECTED ");
	 else if(ChoosenColor==WHITE)
		pOut->PrintMessage("NO SELECTED COLOR  ");


	 else
	{
		if (ChangeFill)
		{
				pManager->GetSelected_Figure()->ChngFillClr(ChoosenColor);
			pOut->SetFillColor(ChoosenColor);
		}

		else
		{
			//pManager->GetSelected_Figure()->ChngFillClr(BLACK);
			pManager->GetSelected_Figure()->ChngDrawClr(ChoosenColor);
			pOut->SetDraColor(ChoosenColor);
		}
	}



}

