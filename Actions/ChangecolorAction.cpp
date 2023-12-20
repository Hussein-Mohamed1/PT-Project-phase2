#include "ChangeColorAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, color c, bool CF):Action(pApp)
{
	DrawColor= c;
	ChangeFill = CF;
	FillColor = GRAY;

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

	if (ChangeFill)
	{
		num_of_fill++;
		pOut->PrintMessage("Choose Fill Color : ");
		ActionType ActType;
		ActType = pIn->GetUserAction();
		switch (ActType)
		{
		case COLOR_BLACK:
			FillColor = BLACK;
			break;
		case COLOR_RED:
			FillColor = RED;
			break;
		case COLOR_BLUE:
			FillColor = BLUE;
			break;
		case COLOR_GREEN:
			FillColor = GREEN;
			break;
		case COLOR_YELLOW:
			FillColor = YELLOW;
			break;
		case COLOR_ORANGE:
			FillColor = ORANGE;
			break;
		default:
			break;
		}
	}

}
void ChangeColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (pManager->GetSelected_Figure() == NULL)
		pOut->PrintMessage("NO SELECTED ");
	else
	{
		if (ChangeFill)
		{
			if(FillColor!=GRAY)
				pManager->GetSelected_Figure()->ChngFillClr(FillColor);
			   pOut->SetFillColor(FillColor);
 		}
		else 
		//pManager->GetSelected_Figure()->ChngFillClr(BLACK);
		pManager->GetSelected_Figure()->ChngDrawClr(DrawColor);
		pOut->SetDraColor(DrawColor);
	}



}

