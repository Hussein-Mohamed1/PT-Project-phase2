#include "figure_typeandcolor.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"
figure_typeandcolor::figure_typeandcolor(ApplicationManager* pApp) :Action(pApp)
{

}
void figure_typeandcolor::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(p.x, p.y);
}
void figure_typeandcolor::Execute()
{
	int n;
	string s;
	by_fig = figures(rand() % 5);
	by_color = colors(rand() % 6);
	n = pManager->numof_figurewithcolor(by_fig, by_color);
	if (n == 0)
		Execute();
	else
	{
		s = "pick all of " + pManager->color_TO_String(by_color) + " " + pManager->figur_TO_String(by_fig) + " ---->click to start";
		pManager->GetOutput()->PrintMessage(s);
		ReadActionParameters();
		while (n)
		{
			s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
			pManager->GetOutput()->PrintMessage(s);
			ReadActionParameters();
			switch (by_fig)
			{
			case squr:
				selected_fig = dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					if (selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
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
					if (selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
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
					if (selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
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
					if (selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
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
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
				}
				break;
			case hexa:
				selected_fig = dynamic_cast<CHexa*>(pManager->GetFigure(p.x, p.y));
				if (selected_fig)
				{
					if (selected_fig->get_fillcolor() == pManager->get_fillcolor(by_color))
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
				}
				else
				{
					incorrect++;
					s = "wrong pick----> correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
					pManager->GetOutput()->PrintMessage(s);
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
