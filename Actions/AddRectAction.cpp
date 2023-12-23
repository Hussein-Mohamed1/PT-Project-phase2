#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
int AddRectAction::numofshapes = 0;
int AddRectAction::getnumofshapes()
{
	return numofshapes;
}



AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{
	//pManager->GetOutput()->PrintMessage(" PLEASE , Wait until sound finished ");
	numofshapes++;
	//// Open the .mp3 file
	//mciSendString(TEXT("open \"D:\\draw-rect2.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"draw-rect2.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);

	// Play the .mp3 file
	mciSendString(TEXT("play mp3"), NULL, 0, NULL);

	// Wait for the sound to finish playing
	Sleep(500);


	//// Close the .mp3 file

	// Close the .mp3 file



}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);

	
	while (!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	pOut->PrintMessage("click second corner");
	pIn->GetPointClicked(P2.x, P2.y);
	while (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5))
	{
		pOut->PrintMessage("wrong click another point ");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	//RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{

	
	
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);

	// close mp3 file
	mciSendString(TEXT("close mp3"), NULL, 0, NULL);

	
}

void AddRectAction::undo()
{
	DeletedFig = pManager->DeleteFigure();
}

void AddRectAction::redo()
{
	pManager->AddFigure(DeletedFig);
}
