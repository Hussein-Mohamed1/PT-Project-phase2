#include "PrepareExport.h"
#include "../ApplicationManager.h"
#include "fstream"
#include "../CMUgraphicsLib/auxil.h"
PrepareExport::PrepareExport(ApplicationManager* pApp) :Action(pApp) {};
void PrepareExport::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Enter The file name or press ESC to cancel.");
}
void PrepareExport::Execute() {
	ReadActionParameters();
	string name = pManager->GetInput()->GetSrting(pManager->GetOutput());
	// checks if the button isn't "-1" i.e ESC and clears the file by using trunc access mode
	fstream* OutputFile = (name != "-1") ? new fstream(name, ios::trunc) : (pManager->GetOutput()->PrintMessage("Save File Cancelled."), 0);
	pManager->GetOutput()->ClearStatusBar();
	if (OutputFile != nullptr) {
		OutputFile->close();
		delete OutputFile;
		OutputFile = nullptr;
		OutputFile = new fstream(name, ios::app | ios::in | ios::out);
		pManager->SaveAll(*OutputFile);
		/*
		Now Each Figures' data will be written after its name and id
		*/
	}
}
void PrepareExport::undo()
{
}
void PrepareExport::redo()
{
}
;