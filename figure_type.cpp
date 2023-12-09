#include "figure_type.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/AddcircleAction.h"
#include "Actions/AddHexaAction.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include <cstdlib> 
figure_type::figure_type(ApplicationManager* pApp) :Action(pApp)
{
	
}
void figure_type::ReadActionParameters()
{

	pManager->GetInput()->GetPointClicked(p.x, p.y);

}
void figure_type::Execute()
{
	
	figures by_fig =figures(rand()%5);
	int n;//num of figure should selected
	switch (by_fig)
	{
	case squr:
		n = AddSquareAction::numofsqar;
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of squares click to start");
		break;
	case rect:
		n = AddRectAction::numofrect;
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of rectangles click to start");
		break;
	case circ:
		n = AddcircleAction::numofcirc;
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of circles click to start");
		break;
	case tria:
		n = AddTriangleAction::numoftria;
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of triangles click to start");
		break;
	case hexa:
		n = AddHexaAction::numofhexa;
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of hexagines click to start");
		break;
	default:
		break;
	}
	if (n == 0)
		Execute();
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	string s = "correct picks="+ to_string(correct)+"\tincorrect picks= "+to_string(incorrect);
	pManager->GetOutput()->PrintMessage(s);
	while (n)
	{
		ReadActionParameters();
		if (pManager->GetFigure(p.x, p.y))
		{
			switch (by_fig)
			{
			case squr:
				selected_fig = dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					//delete figure todo
					correct++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);

				}
				break;
			case rect:
				selected_fig = dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "correct picks=" + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case circ:
				selected_fig = dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case tria:
				selected_fig = dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "correct picks=" + to_string(correct) + "    incorrect picks = " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case hexa:
				selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			default:
				break;
			}
		}
		
	}
	s = "Bravo final record is :  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
	pManager->GetOutput()->PrintMessage(s);
}