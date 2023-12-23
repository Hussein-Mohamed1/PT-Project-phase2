#include "MoveFigure.h"
#include "DeleteAction.h"
#include "../CMUgraphicsLib/auxil.h"
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"
#include "..\ApplicationManager.h"
//int ApplicationManager:: countrepos=0;
//int ApplicationManager:: countpos=0;
moveFigure::moveFigure(ApplicationManager* pApp) :Action(pApp), newPos{ -1,-1 }// countpos{ 0 }, countrepos{ 0 }
{
	

};
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
		Pause(2000);
		pOut->ClearStatusBar();
	}
}
void moveFigure::Execute() {
	ReadActionParameters();
	CFigure* c = pManager->GetSelected_Figure();
	bool f = true;

	if (f&&c!=nullptr) {
		pManager->addPoint(c->GetP1());f = false;
	}

	if ((newPos.x <= UI.width - 5 && newPos.x > 0) && (newPos.y < UI.height - UI.StatusBarHeight - 5) && (newPos.y > UI.ToolBarHeight + 5)) {
		cFigure = pManager->GetSelected_Figure();
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
			//cFigure->
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
		lastPoint = newPos;
		//add the center
		bool notf = false;
		if (notf) {
			pManager->addPoint(c->GetP1());
		}
		notf = true;
	}

}

void moveFigure::undo()
{
	pManager->GetSelected_Figure()->move(pManager->getpoint(ApplicationManager::countpos-1));
	
	ApplicationManager::countpos--;
	ApplicationManager::countrepos++;
	

}

void moveFigure::redo()
{
	//if (ApplicationManager::countrepos==1) pManager->GetSelected_Figure()->move(pManager->getpoint(ApplicationManager::countpos));

	//else 
	//cout << ApplicationManager::countpos + 1 << " " << pManager->getpoint(ApplicationManager::countpos + 1) << endl;
	pManager->GetSelected_Figure()->move(pManager->getpoint( ApplicationManager::countpos +1));

     ApplicationManager::countpos++;
	
	ApplicationManager::countrepos--;
	if (ApplicationManager::countrepos==0) pManager->GetSelected_Figure()->move(lastPoint);

}

moveFigure::~moveFigure()
{

}
