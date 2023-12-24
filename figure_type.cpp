#include "figure_type.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/AddcircleAction.h"
#include "Actions/AddHexaAction.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include <cstdlib> 
#include "Actions/DeleteAction.h"
figure_type::figure_type(ApplicationManager* pApp) :Action(pApp)
{
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetOutput()->CreatePlayToolBar();
	pManager->CopyDeletedFigToFiglist();
	pManager->UpdateInterface();
}
void figure_type::ReadActionParameters()
{

	pManager->GetInput()->GetPointClicked(p.x, p.y);

}
void figure_type::manage_byfigure()
{
	string s;
	if (selected_fig)
	{
		pManager->DeleteFunctionForPlayMood(selected_fig);
		correct++;
		s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		numoffigure--;
	}
	else
	{
		pManager->DeleteFunctionForPlayMood(pManager->GetFigure(p.x , p.y));
		incorrect++;
		s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
	}

}
void figure_type::Execute(bool b)
{

	by_fig = figures(rand() % 5);
	switch (by_fig)
	{
	case squr:
		numoffigure = AddSquareAction::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of squares click to start");
		break;
	case rect:
		numoffigure = AddRectAction::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of rectangles click to start");
		break;
	case circ:
		numoffigure = AddcircleAction::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of circles click to start");
		break;
	case tria:
		numoffigure = AddTriangleAction::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of triangles click to start");
		break;
	case hexa:
		numoffigure = AddHexaAction::getnumofshapes();
		if (numoffigure != 0)
			pManager->GetOutput()->PrintMessage("pick all of hexagines click to start");
		break;
	default:
		break;
	}
	
	if (numoffigure == 0)
		Execute( b);
	else
	{
		pManager->GetInput()->GetPointClicked(p.x, p.y);
		string s = "correct picks=" + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		while (numoffigure && (p.y > 50))
		{
			ReadActionParameters();
			if (pManager->GetFigure(p.x, p.y))
			{
				switch (by_fig)
				{
				case squr:
					selected_fig = dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case rect:
					selected_fig = dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case circ:
					selected_fig = dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case tria:
					selected_fig = dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				case hexa:
					selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
					manage_byfigure();
					break;
				default:
					break;
				}
			}
		}
		if (correct > incorrect)
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  BRAVOOO";
			pManager->GetOutput()->PrintMessage(s);
		}
		else if (incorrect > correct)
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  not good, try again";
			pManager->GetOutput()->PrintMessage(s);
		}
		else
		{
			s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  not bad";
			pManager->GetOutput()->PrintMessage(s);
		}
	}
}

