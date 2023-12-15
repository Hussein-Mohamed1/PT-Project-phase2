#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
int AddSquareAction::numofsqar = 0;
 AddSquareAction ::AddSquareAction(ApplicationManager * pApp) :Action(pApp)
 {}
 void AddSquareAction::ReadActionParameters()
 {

	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 pOut->PrintMessage("New Square : Click at Centre ");

	 pIn->GetPointClicked(P1.x, P1.y);
	 P2.x = P1.x + 60;
	 P2.y = P1.y + 60;
	 P1.x -= 60;
	 P1.y -= 60;
	 while ((!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5)) || (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5)) || (P1.x < 5 || P2.x >= UI.width - 15))
	 {
		 pOut->PrintMessage("wrong click another center");
		 pIn->GetPointClicked(P1.x, P1.y);
		 P2.x = P1.x + 60;
		 P2.y = P1.y + 60;
		 P1.x -= 60;
		 P1.y -= 60;
	 }

	// RectGfxInfo.isFilled = false;	//default is not filled
	 //get drawing, filling colors and pen width from the interface
	 RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	 RectGfxInfo.FillClr = pOut->getCrntFillColor();

	 pOut->ClearStatusBar();

 }
 void AddSquareAction::Execute()
 {
	 numofsqar++;
	 ReadActionParameters();

	 // Make a new square 

	 CSquare* s = new CSquare(P1, P2, RectGfxInfo);

	 // Add Square to figure list 
	  
	 pManager->AddFigure(s);

 }



