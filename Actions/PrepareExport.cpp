#include "PrepareExport.h"
#include "../ApplicationManager.h"
#include "fstream"
#include "../CMUgraphicsLib/auxil.h"
PrepareExport::PrepareExport(ApplicationManager* pApp) :Action(pApp) {};
void PrepareExport::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Enter The file name without .txt or press ESC to cancel.");
	name = pManager->GetInput()->GetString(pManager->GetOutput());
}
void PrepareExport::Execute() {
	ReadActionParameters();
	name += ".txt";
	// checks if the button isn't "-1" i.e ESC and clears the file by using trunc access mode
	fstream* OutputFile = (name != "-1.txt") ? new fstream(name, ios::trunc) : (pManager->GetOutput()->PrintMessage("Save File Cancelled."), 0);
	// the fstream object is created with trunc mode to delete any text inside of the file
	pManager->GetOutput()->ClearStatusBar();
	if (OutputFile != nullptr) {
		OutputFile->close();
		delete OutputFile;
		OutputFile = nullptr;
		OutputFile = new fstream(name, ios::app | ios::out);
		pManager->SaveAll(*OutputFile); // 		Now Each Figures' data will be written after its name and id

	}
};