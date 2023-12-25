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
//	CFigure pfig=
	cFigure = pManager->GetSelected_Figure();


	/***/

	if (ApplicationManager::countpos==0)
	pManager->addPoint(cFigure->GetP1());
	/***/
	if (cFigure != nullptr)
	{


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
			ReadActionParameters();
			move();
		}
	}
	else moveByDragging();
}

bool moveFigure::move() {
	if (!byDragging)
	{
        if (cFigure != nullptr) {
			pManager->addPoint(cFigure->GetP1());
		 }
		/**/
	}
	pManager->set_figure(cFigure);
	if ((newPos.x <= UI.width - 5 && newPos.x > 0) && (newPos.y < UI.height - UI.StatusBarHeight - 5) && (newPos.y > UI.ToolBarHeight + 5)) {
		{if (dynamic_cast<CCircle*>(cFigure) != nullptr) {
			if (cFigure->isInsideWindowBoundaries(newPos))
			{
				cFigure->move(newPos);
				return 1;
			}
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				return 0;
			}
		}
		if (dynamic_cast<CHexa*>(cFigure) != nullptr) {
			if (cFigure->isInsideWindowBoundaries(newPos))
			{
				cFigure->move(newPos);
				return 1;
			}
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				return 0;
			}
		}
		if (dynamic_cast<CRectangle*>(cFigure) != nullptr) {
			if (cFigure->isInsideWindowBoundaries(newPos))
			{
				cFigure->move(newPos);
				return 1;
			}
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				return 0;
			}
		}
		if (dynamic_cast<CSquare*>(cFigure) != nullptr) {
			if (cFigure->isInsideWindowBoundaries(newPos))
			{
				cFigure->move(newPos);
				return 1;
			}
			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				return 0;
			}
		}
		if (dynamic_cast<CTriangle*>(cFigure) != nullptr) {
			if (cFigure->isInsideWindowBoundaries(newPos))
			{
				cFigure->move(newPos);
				return 1;
			}

			else {
				pManager->GetOutput()->PrintMessage("Invalid Position! Please try again.....");
				Pause(1000);
				pManager->GetOutput()->ClearStatusBar();
				return 0;
			}
		}
		}

		pManager->UpdateInterface();
	}
	//lastPoint = newPos;
	//add the center
//	bool notf = false;
//	if (notf) {
	//if (ApplicationManager::countpos==0)
		//ApplicationManager::countpos++;
	/*******************/
		pManager->addPoint(cFigure->GetP1());
	/*********************/
	
		cout << pManager->getpoint(ApplicationManager::countpos ) << " " << ApplicationManager::countpos  << " " << endl;
	//}
	//notf = true;

}

void moveFigure::moveByDragging() {
	int iX = 0, iY = 0;
	Input* pIn = pManager->GetInput();
	buttonstate btnstate = pIn->GetButtonState(LEFT_BUTTON, iX, iY); // just puts the current coords to iX and iY, nothing else
	if (cFigure == nullptr || cFigure == reinterpret_cast<decltype(cFigure)>(0xffffffff))
	{
		pManager->GetOutput()->PrintMessage("lolll");
		cFigure = nullptr;
		return;
	}
	else
		if (cFigure->checkselection(iX, iY) == true) {
			Pause(100);// necessary delay to capture the users double tap on a shape
			btnstate = pIn->GetButtonState(LEFT_BUTTON, iX, iY);
			while (pIn->GetButtonState(LEFT_BUTTON, iX, iY) != BUTTON_UP) {
				newPos = Point{ iX,iY };
				if (!move())
					break;
				Pause(80); // necessary delay to avoid breaking the gui
				pManager->UpdateInterface();

			}
		}

	pManager->addPoint(newPos);
}

void moveFigure::addundofirst(Action* pAct)
{
	pManager->addToUndo(this);
}



void moveFigure::undo()
{
	cFigure->move(pManager->getpoint(ApplicationManager::countpos - 1));
    cout << pManager->getpoint(ApplicationManager::countpos - 1) << " " << ApplicationManager::countpos - 1 << " "<<endl;
	ApplicationManager::countpos--;
	ApplicationManager::countrepos++;

	
}

void moveFigure::redo()
{
	
	cFigure->move(pManager->getpoint(ApplicationManager::countpos + 1));
	cout << pManager->getpoint(ApplicationManager::countpos + 1) << " "<<ApplicationManager::countpos + 1<<" "<<endl;
	//ApplicationManager::countpos++;
	ApplicationManager::countrepos--;
	if (ApplicationManager::countrepos == 0) cFigure->move(lastPoint);

}


