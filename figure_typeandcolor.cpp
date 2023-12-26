#include "figure_typeandcolor.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
figure_typeandcolor::figure_typeandcolor(ApplicationManager* pApp) :Action(pApp)
{
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetOutput()->CreatePlayToolBar();
	pManager->CopyDeletedFigToFiglist();
	pManager->UpdateInterface();
}
void figure_typeandcolor::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(p.x, p.y);
}
void figure_typeandcolor::manage_typeandcolor()
{
	string s;
	if (selected_fig && selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
	{
		pManager->DeleteFunctionForPlayMood(selected_fig);
		correct++;
		s = "nice pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		numoffigbycolor--;
	}
	else
	{
		pManager->DeleteFunctionForPlayMood(pManager->GetFigure(p.x, p.y));
		incorrect++;
		s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
	}
}
void figure_typeandcolor::Execute(bool b)
{
	string s;
	by_fig = figures(rand() % 5);
	by_color = colors(rand() % 6);
	numoffigbycolor = pManager->numof_figurewithcolor(by_fig, by_color);
	if (numoffigbycolor == 0)
		Execute(b);
	else
	{
		s = "pick all of " + pManager->color_TO_String(by_color) + " " + pManager->figur_TO_String(by_fig) + " ---->click to start";
		pManager->GetOutput()->PrintMessage(s);
		ReadActionParameters();
		s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
		pManager->GetOutput()->PrintMessage(s);
		while (numoffigbycolor && (p.y>50))
		{
			ReadActionParameters();
			switch (by_fig)
			{
			case squr:
				if (pManager->GetFigure(p.x, p.y))
				{
					selected_fig = dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y));
					manage_typeandcolor();
				}
					
				break;
			case rect:
				if (pManager->GetFigure(p.x, p.y))
				{
					selected_fig = dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y));
					manage_typeandcolor();
				}
				break;
			case circ:
				if (pManager->GetFigure(p.x, p.y))
				{
					selected_fig = dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y));
					manage_typeandcolor();
				}
				break;
			case tria:
				if (pManager->GetFigure(p.x, p.y))
				{
					selected_fig = dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y));
					manage_typeandcolor();
				}
				break;
			case hexa:
				if (pManager->GetFigure(p.x, p.y))
				{
					selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
					manage_typeandcolor();
				}
				break;
			default:
				break;
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
