#include "ChangeColorAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, color c) :Action(pApp)
{
	C = c;
}
void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
}
void ChangeColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (pManager->GetSelected_Figure() == NULL)
		pOut->PrintMessage("NO SELECTED ");
	else
	{
		//pManager->GetSelected_Figure()->ChngFillClr(BLACK);
		pManager->GetSelected_Figure()->ChngDrawClr(C);
		pOut->SetDraColor(C);
	}



}

