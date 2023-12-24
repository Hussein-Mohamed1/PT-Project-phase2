#include "StartandStopRec.h"
StartandStopRec::StartandStopRec(ApplicationManager* pApp) :Action(pApp)
{
	arr_Actions = new Action*[20];

}
void StartandStopRec::ReadActionParameters()
{
	current_action = pManager->GetUserAction();
}
void StartandStopRec::Execute()
{
	pManager->GetOutput()->PrintMessage("recording is working...");
	int numofaction=0;
	while (!stop_rec || numofaction>20)
	{
		ReadActionParameters();
		pManager->GetOutput()->PrintMessage("recording is working...");
		if (current_action > 22)
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
			pManager->ExecuteAction(current_action , arr_Actions[numofaction++]);
			pManager->UpdateInterface();
		}
	}
	pManager->GetOutput()->PrintMessage("recording stop...");
}
StartandStopRec::~StartandStopRec()
{
	
}