#include "AddTriangleAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CTriangle.h"

 
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp)
{}
void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at 3 points ");

	bool invalid = 1;

	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
		pIn->GetPointClicked(P3.x, P3.y);

		if ((P1.y) < (UI.ToolBarHeight + 5) || (P2.y) < (UI.ToolBarHeight + 5) || (P3.y) < (UI.ToolBarHeight + 5) || (P1.y) > (UI.height - UI.StatusBarHeight + 5) || (P2.y) > (UI.height - UI.StatusBarHeight + 5) || (P3.y) > (UI.height - UI.StatusBarHeight + 5)) // window - status bar height to get y coordinate of statusbar
		{
			pOut->PrintMessage("In Valid points , Please Click points in drawing area ");

		}
		else invalid = false;

	} while (invalid);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();


}
void AddTriangleAction::Execute()  
{
	
	// Read Parametes first 
	ReadActionParameters();

	// create a Triangle 

	CTriangle* T = new CTriangle(P1, P2, P3, RectGfxInfo);

    // Add Triangle to Figures
	pManager->AddFigure(T);

}

