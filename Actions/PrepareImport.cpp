#include "PrepareImport.h"
#include "../ApplicationManager.h"
#include "fstream"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CSquare.h"
#include "../Figures/CRectangle.h"

#include "../DEFS.h"
#include <sstream>
#include "../CMUgraphicsLib/auxil.h"

PrepareImport::PrepareImport(ApplicationManager* pApp) :Action(pApp) {};
void PrepareImport::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Enter The file name or press ESC to cancel.");


}
void PrepareImport::Execute() {
	ReadActionParameters();
	string name = pManager->GetInput()->GetSrting(pManager->GetOutput());
	// checks if the button isn't "-1" i.e ESC
	fstream* OutputFile = (name != "-1") ? new fstream(name, ios::in) : (pManager->GetOutput()->PrintMessage("Load File Cancelled."), 0);
	pManager->GetOutput()->ClearStatusBar();
	if (OutputFile != nullptr) {
		{if (OutputFile->is_open())
		{
			CFigure* p = nullptr;
			string line;

			while (getline(*OutputFile, line)) {
				stringstream ss(line);           // string stream is used as it splits the line based on white spaces
				string temp;
				ss >> temp;

				if (temp == "Triangle:") {
					p = new CTriangle();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (temp == "Hexagon:") {
					p = new CHexa();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (temp == "Rectangle:") {
					p = new CRectangle();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (temp == "Circle:") {
					p = new CCircle();
					p->Load(line);
					pManager->AddFigure(p);
				}
				else if (temp == "Square:") {

					p = new CSquare();
					p->Load(line);
					pManager->AddFigure(p);
				}
			}
			pManager->GetOutput()->ClearDrawArea();
			pManager->UpdateInterface();
		}

		else {
			pManager->GetOutput()->PrintMessage("File Not Found.");
			Pause(2000);
			pManager->GetOutput()->ClearStatusBar();
		}
		}
	}
}
void PrepareImport::undo()
{
}
void PrepareImport::redo()
{
}
;