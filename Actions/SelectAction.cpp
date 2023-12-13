#include "SelectAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


//CFigure* SelectAction::Selected_Figure = NULL;

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}
 
void SelectAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("  Select a Figure   ");

	pIn->GetPointClicked(p.x, p.y);

}

void SelectAction::Execute()
{

	  ReadActionParameters();

	  pManager->GetFigure(p.x, p.y);

}
//CFigure* SelectAction::GetSelected_Figure()
//{
//	return Selected_Figure;
//}
