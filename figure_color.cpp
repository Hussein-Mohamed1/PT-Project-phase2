#include "figure_color.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
figure_color::figure_color(ApplicationManager* pApp):Action(pApp)
{

}
void figure_color::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	
}
void figure_color::manage_by_color(color c , int n)
{
	string s;
	s = "correct picks= " + to_string(correct) + "    incorrect picks= " + to_string(incorrect);
	pManager->GetOutput()->PrintMessage(s);
	while (n)
	{
		ReadActionParameters();
		selected_fig = pManager->GetFigure(p.x, p.y);
		if (selected_fig)
		{
			if (selected_fig->get_fillcolor() == c)
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
	}
}
void figure_color::Execute()
{
	string s;
	 by_color = colors(rand() % 6);
	int n;//num of figure should selected_by_colors
	switch (by_color)
	{
	case black:
		n=pManager->get_numofcolor(BLACK);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of black figures click to start");
			ReadActionParameters();
			manage_by_color(BLACK, n);
		}
		else
			Execute();
		break;
	case red:
		n = pManager->get_numofcolor(RED);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of red figures click to start");
			ReadActionParameters();
			manage_by_color(RED, n);
		}
		else
			Execute();
		break;
	case blue:
		n = pManager->get_numofcolor(BLUE);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of blue figures click to start");
			ReadActionParameters();
			manage_by_color(BLUE, n);
		}
		else
			Execute();
		break;
	case green:
		n = pManager->get_numofcolor(GREEN);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of green figures click to start");
			ReadActionParameters();
			manage_by_color(GREEN, n);
		}
		else
			Execute();
		break;
	case yellow:
		n = pManager->get_numofcolor(YELLOW);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of yellow figures click to start");
			ReadActionParameters();
			manage_by_color(YELLOW, n);
		}
		else
			Execute();
		break;
	case orange:
		n = pManager->get_numofcolor(ORANGE);
		if (n != 0)
		{
			pManager->GetOutput()->PrintMessage("pick all of orange figures click to start");
			ReadActionParameters();
			manage_by_color(ORANGE, n);
		}
		else
			Execute();
		break;
	default:
		break;
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