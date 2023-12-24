#include "StartandStopRec.h"
StartandStopRec::StartandStopRec(ApplicationManager* pApp) :Action(pApp)
{
}
void StartandStopRec::ReadActionParameters()
{
	current_action = pManager->GetUserAction();
}
void StartandStopRec::Execute(bool b)
{
	pManager->GetOutput()->PrintMessage("recording is working...");
	int numofaction=0;
	while (!stop_rec || numofaction>20)
	{
		ReadActionParameters();
		pManager->GetOutput()->PrintMessage("recording is working...");
		if (current_action > FUNC_STOP_REC)
			pManager->GetOutput()->PrintMessage("can't recording this action choose anothor action");
		else if (current_action == DRAWING_AREA || current_action == STATUS || current_action == EMPTY)
			continue;
		else if (current_action == FUNC_STOP_REC)
		{
			stop_rec = true;
			pManager->GetOutput()->PrintMessage("recording stop...");
		}
		else
		{
			pManager->ExecuteAction(current_action , numofaction++);
			pManager->UpdateInterface();
		}
	}
	pManager->GetOutput()->PrintMessage("recording stop...");
}
StartandStopRec::~StartandStopRec()
{
	
}