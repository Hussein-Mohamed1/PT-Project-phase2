#include "ChangecolorAction.h"
#include"../Actions/SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangecolorAction::ChangecolorAction(ApplicationManager* pApp , color C) : Action(pApp)
{
	Selected_Figure = NULL;
	F_COLOR = C;

}
void ChangecolorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Selected_Figure = SelectAction::GetSelected_Figure();

	if (Selected_Figure == NULL)
		pOut->PrintMessage(" NO Selected Figure , Plese click on Select icon then choose figure then color");

   
}
void ChangecolorAction::Execute()
{
	ReadActionParameters();

		pManager->Change_Color(Selected_Figure, F_COLOR);

}