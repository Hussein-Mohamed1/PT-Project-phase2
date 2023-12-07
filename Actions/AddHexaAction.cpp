#include "AddHexaAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CHexa.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction( ApplicationManager * pApp):Action(pApp)
{}
void AddHexaAction::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("New Hexagon: Click at centre point ");
	int invalid = 1;

	do
	{
		pIn->GetPointClicked(P1.x, P1.y);  // CENTRE OF HEXA
		if ((P1.y) - 80 < (UI.ToolBarHeight + 5) || (P1.y) + 61 > (UI.height - UI.StatusBarHeight + 5)  //  vertical validation : window hieght - tool bat height + 5 to be in safe
			|| ((P1.x) + 80) > (UI.width - 5) || (P1.x) - 80 < 0)           // horizontal validation 
		{
			pOut->PrintMessage("Invalid centre , click anthor centre ");

		}
		else invalid = 0;

	} while (invalid);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddHexaAction::Execute()
{
	ReadActionParameters();

	/// create New Hexa

	CHexa* H = new CHexa(P1, RectGfxInfo);

	// Add Hexa to Fig List

	pManager->AddFigure(H);
}
