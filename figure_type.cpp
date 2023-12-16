#include "figure_type.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
#include <cstdlib> 
#include "Actions/DeleteAction.h"
figure_type::figure_type(ApplicationManager* pApp) :Action(pApp)
{
	
}
void figure_type::ReadActionParameters()
{

	pManager->GetInput()->GetPointClicked(p.x, p.y);

}
void figure_type::Execute()
{
	
	 by_fig =figures(rand()%5);
	int n;//num of figure should selected
	switch (by_fig)
	{
	case squr:
		n = CSquare::get_numofshape();
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of squares click to start");
		break;
	case rect:
		n = CRectangle::get_numofshape();
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of rectangles click to start");
		break;
	case circ:
		n = CCircle::get_numofshape();
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of circles click to start");
		break;
	case tria:
		n = CTriangle::get_numofshape();
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of triangles click to start");
		break;
	case hexa:
		n = CHexa::get_numofshape();
		if (n != 0)
			pManager->GetOutput()->PrintMessage("pick all of hexagines click to start");
		break;
	default:
		break;
	}
	if (n == 0)
		Execute();
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	string s = "correct picks="+ to_string(correct)+ "    incorrect picks= "+to_string(incorrect);
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
					s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);

				}
				break;
			case rect:
				selected_fig = dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "nice pick----> correct picks=" + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case circ:
				selected_fig = dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case tria:
				selected_fig = dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks=" + to_string(correct) + "    incorrect picks = " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case hexa:
				selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					correct++;
					s = "nice pick----> correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
					n--;
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			default:
				break;
			}
		}
		else
		{
			incorrect++;
			s = "wrong pick----> correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect);
			pManager->GetOutput()->PrintMessage(s);
		}
	}
	if (correct > incorrect)
	{
		s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect)+"  BRAVOOO";
		pManager->GetOutput()->PrintMessage(s);
	}
	else if (incorrect > correct)
	{
		s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect)+"  not good, try again";
		pManager->GetOutput()->PrintMessage(s);
	}
	else
	{
		s = "final record is---->  correct picks=  " + to_string(correct) + "    incorrect picks=  " + to_string(incorrect) + "  not bad";
		pManager->GetOutput()->PrintMessage(s);
	}
}