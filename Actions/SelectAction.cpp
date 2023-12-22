#include "SelectAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"



SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	ClickedFigure = NULL;

}

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
	Output* pOut = pManager->GetOutput();

	ClickedFigure = pManager->GetFigure(p.x, p.y);
	CFigure* Selected_Figure = pManager->GetSelected_Figure();
	if (Selected_Figure == NULL)
	{
		Selected_Figure = ClickedFigure;
		Selected_Figure->SetSelected(true);
		Selected_Figure->PrintInfo(pOut);
	}

	// case two if selected figure is seclected before make it unselected and return NUL

	else if (Selected_Figure == ClickedFigure)
	{
		Selected_Figure->SetSelected(false);
		Selected_Figure = NULL;
	}

	//  case 3 if the seleced figure isn't the selected before

	else            //if (Selected_Figure != FigList[i])            
	{
		Selected_Figure->SetSelected(false);
		Selected_Figure = ClickedFigure;
		Selected_Figure->SetSelected(true);
		Selected_Figure->PrintInfo(pOut);
	}



}

void SelectAction::undo()
{
}

void SelectAction::redo()
{
	if (ClickedFigure)
	{
	/*	pManager->SetSelectedFig(ClickedFigure);
		ClickedFigure = NULL;*/
	}
}
