#include "DeleteAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
	deletedFigure = nullptr;
}
void DeleteAction::ReadActionParameters()
{


}
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();


	if (pManager->GetSelected_Figure() == NULL)
		pOut->PrintMessage("NO SELECTED ");
	else
	{
		pManager->DeleteFunction();
	}


}
