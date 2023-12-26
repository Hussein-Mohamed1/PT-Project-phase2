#include "MoveFigure.h"
#include "DeleteAction.h"
#include "../CMUgraphicsLib/auxil.h"
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"

moveFigure::moveFigure(ApplicationManager* pApp, bool byDragging) :Action(pApp), newPos{ -1,-1 }, byDragging(byDragging), cFigure(nullptr) {

};

void moveFigure::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	cFigure = pManager->GetSelected_Figure();

	if (cFigure != nullptr)
	{
		newPos = (cFigure->GetP1());
		pOut->PrintMessage("Click a point to move the figure to.");
		pIn->GetPointClicked(newPos.x, newPos.y);
		//pManager->GetFigure(newPos.x, newPos.y);

		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("Choose a figure first then try again!");
		Pause(1000);
		pManager->GetInput()->FlushMouseQueue(); /*written to stop the user from spamming
		 the move button when there is no figure as the pause functionality doesnt clear the mouse queue by default*/
		pOut->ClearStatusBar();
	}
}
void moveFigure::Execute(bool b) {
	cFigure = pManager->GetSelected_Figure();
	if (!byDragging)
	{
		if (b)
		{
			if (cFigure != nullptr)
			{
				ReadActionParameters();
				move();
			}
		}
	}
	else moveByDragging();
}

void moveFigure::move(bool notaReverseAction) {
	if (!byDragging && cFigure != nullptr && notaReverseAction == true)
	{
		lastPoint = cFigure->GetP1();
	}
	pManager->set_figure(cFigure);
	if ((newPos.x <= UI.width - 5 && newPos.x > 0) && (newPos.y < UI.height - UI.StatusBarHeight - 5) && (newPos.y > UI.ToolBarHeight + 5)) {
		if (cFigure->isInsideWindowBoundaries(newPos))
		{
			cFigure->move(newPos);
		}
		else {
			pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
			Pause(1000);
			pManager->GetOutput()->ClearStatusBar();
		}
		pManager->UpdateInterface();
	}
}

void moveFigure::moveByDragging() {
	Input* pIn = pManager->GetInput();
	pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y); // just puts the current coords to iX and iY, nothing else
	if (cFigure->checkselection(newPos.x, newPos.y) == true) {
		lastPoint = cFigure->GetP1();
		Sleep(200);// necessary delay to capture the users double tap on a shape
		while (pIn->GetButtonState(RIGHT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN || pIn->GetButtonState(LEFT_BUTTON, newPos.x, newPos.y) == BUTTON_DOWN) {
			if (cFigure->isInsideWindowBoundaries(newPos))
				move();
			else
			{
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				break;
			}
			Sleep(80); // necessary delay to avoid breaking the gui
			cFigure->PrintInfo(pManager->GetOutput());
			pManager->UpdateInterface();

		}
	}
}

void moveFigure::addundofirst(Action* pAct)
{

}



void moveFigure::undo()
{
	swap(lastPoint, newPos);
	move(false);
}

void moveFigure::redo()
{
	swap(lastPoint, newPos);
	move(false);
}