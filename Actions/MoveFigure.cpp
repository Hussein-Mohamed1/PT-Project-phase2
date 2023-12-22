#include "MoveFigure.h"
#include "../CMUgraphicsLib/auxil.h"
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"

moveFigure::moveFigure(ApplicationManager* pApp) :Action(pApp), newPos{ -1,-1 } {};
void moveFigure::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelected_Figure() != nullptr)
	{
		pOut->PrintMessage("Click a point to move the figure to.");
		pIn->GetPointClicked(newPos.x, newPos.y);
		pManager->GetFigure(newPos.x, newPos.y);
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
void moveFigure::Execute() {
	ReadActionParameters();

	if ((newPos.x <= UI.width - 5 && newPos.x > 0) && (newPos.y < UI.height - UI.StatusBarHeight - 5) && (newPos.y > UI.ToolBarHeight + 5)) {
		CFigure* cFigure = pManager->GetSelected_Figure();
		{if (dynamic_cast<CCircle*>(cFigure) != nullptr) {
			if (cFigure->isInsideBoundaries(newPos))
				cFigure->move(newPos);
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
			}
		}
		if (dynamic_cast<CHexa*>(cFigure) != nullptr) {
			if (cFigure->isInsideBoundaries(newPos))
				cFigure->move(newPos);
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
			}
		}
		if (dynamic_cast<CRectangle*>(cFigure) != nullptr) {
			if (cFigure->isInsideBoundaries(newPos))
				cFigure->move(newPos);
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
			}
		}
		if (dynamic_cast<CSquare*>(cFigure) != nullptr) {
			if (cFigure->isInsideBoundaries(newPos))
				cFigure->move(newPos);
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
			}
		}
		if (dynamic_cast<CTriangle*>(cFigure) != nullptr) {
			if (cFigure->isInsideBoundaries(newPos))
				cFigure->move(newPos); 
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
			}
		}
		}

		pManager->UpdateInterface();
	}

}