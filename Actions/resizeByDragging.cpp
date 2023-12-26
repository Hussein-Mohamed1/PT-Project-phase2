#include "resizeByDragging.h"
#include "../CMUgraphicsLib/auxil.h"

resizeByDragging::resizeByDragging(ApplicationManager* pApp) : Action(pApp)
{
}

void resizeByDragging::Execute(bool b)
{
	if (b) {
		Point newPos;
		Input* pIn = pManager->GetInput();
		CFigure* sFigure = pManager->GetSelected_Figure();
		pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y); // just puts the current coords to iX and iY, nothing else
		int cornerNumber = sFigure->OutlineClickValidation(newPos);
		if (cornerNumber) { // checks if the mouse is on the outlines of the selected figure
			Sleep(200);// necessary delay to capture the users double tap on a shape
			while (pIn->GetButtonState(RIGHT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN ||
				pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN)
			{
				if (sFigure->isInsideWindowsBoundaries(sFigure->GetCenter()))
					sFigure->resize(newPos);
				else
				{
					pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
					Pause(1000);
					pManager->GetOutput()->ClearStatusBar();
					break;
				}
				Sleep(80); // necessary delay to avoid breaking the gui
				sFigure->PrintInfo(pManager->GetOutput());
				pManager->UpdateInterface();

			}
		}
	}
}

void resizeByDragging::ReadActionParameters()
{

}
