#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddcircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions/AddSquareAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/SelectAction.h"
#include "Actions/PrepareExport.h"
#include "Actions/PrepareImport.h"
#include "Actions/MoveFigure.h"
#include "fstream"
#include "Figures/CCircle.h"
#include "to_playmood.h"
#include "figure_type.h"
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include "to_drawmood.h"
#include"Actions/ChangeColorAction.h"
#include"DEFS.h"
#include"Actions/DeleteAction.h"
#include "figure_color.h"
#include "figure_typeandcolor.h"
#include"to_playmood.h"
using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{	

	// Initializes the current selected figure pointer to null;
	Selected_Figure = nullptr;
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	DeletedFigCount = 0;
	Selected_Figure = NULL;


	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		DeletedFigList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddcircleAction(this);
		break;
	case DRAW_TRIA:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_SQUA:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_HEXA:
		pAct = new AddHexaAction(this);
		break;
	case FUNC_SELECT:
		pAct = new SelectAction(this);
		break;
	case FUNC_SAVE:
		pAct = new PrepareExport(this);
		break;
	case FUNC_LOAD:
		pAct = new PrepareImport(this);
		break;
	case ENTER_PLAY_MODE:
		pAct = new to_playmood(this);
		break;
	case BY_SHAPE:
		if(FigCount)
		pAct = new figure_type(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case BY_COLOR:
		if(ChangeColorAction::if_exist_file())
		pAct = new figure_color(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case BY_COLOR_SHAPE:
		if (ChangeColorAction::if_exist_file())
			pAct = new figure_typeandcolor(this);
		else
			pOut->PrintMessage("no figures to pick it");
		break;
	case COLOR_BLACK:
	pAct = new ChangeColorAction(this,BLACK);
		break;
	case COLOR_RED:
	pAct = new ChangeColorAction(this,RED);
		break;
	case COLOR_GREEN :
		pAct = new ChangeColorAction(this, GREEN);
		break;
	case COLOR_ORANGE:
		pAct = new ChangeColorAction(this, ORANGE);
		break;
	case COLOR_YELLOW:
		pAct = new ChangeColorAction(this, YELLOW);
		break;
	case COLOR_BLUE:
		pAct = new ChangeColorAction(this, BLUE);
		break;
	case FUNC_FILL:
		pAct = new ChangeColorAction(this,BLUE,1);
		break;
	case FUNC_DELETE :
		pAct = new DeleteAction(this);
		break;
	case FUNC_EXIT_playMode:
		pAct = new to_drawmood(this);
		break;


	case FUNC_EXIT:
		///create ExitAction here
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{

	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;

}
void ApplicationManager::AddDeletedFig(CFigure* del)
{
	if (DeletedFigCount < MaxFigCount)
		DeletedFigList[DeletedFigCount++] =del;

}

////////////////////////////////////////////////////////////////////////////////////

CFigure* ApplicationManager::GetFigure(int x, int y)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)                  // Validation to prevent crash if Figure is deleted
		{
			if (FigList[i]->checkselection(x, y))           /// to check whether point is in figure or not
			{
				//SetSelectedFig(FigList[i]);
				return FigList[i];

			}

		}


	}

				  // if the point dosen't belong to any figure

	pOut->PrintMessage(" No selected figure ");

	//Add your code here to search for a figure given a point x,y
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}



//bool ApplicationManager :: Select(CFigure* figure)
//{
//	if (Selected_Figure==figure) {
//		Selected_Figure->SetSelected(false);
//		Selected_Figure = nullptr;
//	}
//	else if (Selected_Figure == nullptr)
//	{
//		Selected_Figure = figure;
//		Selected_Figure->SetSelected(true);
//	}
//	else  //if (Selected_Figure != figure)
//	{
//		Selected_Figure->SetSelected(false);
//		Selected_Figure = nullptr;
//		Selected_Figure = figure;
//		Selected_Figure->SetSelected(true);
//
//	}
//
//}
//
//CFigure* ApplicationManager:: GetFigureByPoint(int x, int y)
//{
//	for (int i = 0; i < FigCount; i++)
//	{
//		if (FigList[i]->checkselection(x, y))
//		{
//			return FigList[i];
//		}
//	}
//}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() 
{
		pOut->ClearDrawArea();                 

		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i] !=NULL)
				FigList[i]->Draw(pOut);
		}

}

void ApplicationManager::DeleteFunction()
{
	for (int  i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Selected_Figure)
		{
			//Selected_Figure->SetSelected(false);             
	       //		pOut->ClearDrawArea();                 
			pOut->ClearStatusBar();
		    FigList[i] = NULL;
			Selected_Figure = NULL;
			break;
		}
	}
}
void ApplicationManager::DeleteFunctionForPlayMood(CFigure* Del)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Del)
		{
			AddDeletedFig(FigList[i]);
			FigList[i] = NULL;
			UpdateInterface();
			break;
		}
	}
}
void  ApplicationManager::CopyDeletedFigToFiglist()
{
	for (int i = 0; i < DeletedFigCount; i++)
	{
		if (DeletedFigList[i] != NULL)
		{
			for (int j = 0; j <FigCount; j++)
			{
				if (FigList[j] == NULL)
				{
					FigList[j] = DeletedFigList[i];
					DeletedFigList[i] = NULL;
					break;
				}

			}

		}
	}
}


	////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
// Makes Each Figure save its data
void ApplicationManager::SaveAll(fstream& OutputFile) const {
	if (OutputFile.good()) {
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i] != nullptr)
				FigList[i]->Save(OutputFile);
		}
		OutputFile.close();
	}
}

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		delete DeletedFigList[i];
	}
	delete pIn;
	delete pOut;

}
  CFigure* ApplicationManager::GetSelected_Figure() 
{
	return Selected_Figure;
}
  void  ApplicationManager::SetSelectedFig(CFigure* S)
  {
	  // case one if there is no selected figure before 

	  if (Selected_Figure == NULL)
	  {
		  Selected_Figure = S;
		  Selected_Figure->SetSelected(true);
		  Selected_Figure->PrintInfo(pOut);
	  }

	  // case two if selected figure is seclected before make it unselected and return NUL

	  else if (Selected_Figure == S)
	  {
		  Selected_Figure->SetSelected(false);
		  Selected_Figure = NULL;
	  }

	  //  case 3 if the seleced figure isn't the selected before

	  else            //if (Selected_Figure != FigList[i])            
	  {
		  Selected_Figure->SetSelected(false);
		  Selected_Figure = S;
		  Selected_Figure->SetSelected(true);
		  Selected_Figure->PrintInfo(pOut);
	  }


  }

  
  void ApplicationManager::set_figure(CFigure* fig)
  {
	  Selected_Figure = fig;
  }

  /*
  * 
  *   CFigure* ApplicationManager::GetFigure(int x, int y)
	  {
	  	for (int i = 0; i < FigCount; i++)
	  {  
	  		if (FigList[i] != NULL)                  // Validation to prevent crash if Figure is deleted 
	 	{
	  			if (FigList[i]->checkselection(x, y))           /// to check whether point is in figure or not 
	  			{
	  				// case one if there is no selected figure before 
	  
	  				if (Selected_Figure == NULL)               
	 				{
	  					Selected_Figure = FigList[i];
	  					Selected_Figure->SetSelected(true);
	  					Selected_Figure->PrintInfo(pOut);
	  					return Selected_Figure;
	 				}
	  
	  				// case two if selected figure is seclected before make it unselected and return NUL
	  
	  				else if (Selected_Figure == FigList[i])          
	  				{
	  					Selected_Figure->SetSelected(false);
	  					Selected_Figure = NULL;
	  					return NULL;
	  				}
	  
	  				  //  case 3 if the seleced figure isn't the selected before
	  
	  				else            //if (Selected_Figure != FigList[i])            
	  				{
	  					Selected_Figure->SetSelected(false);
	  					Selected_Figure = FigList[i];
	  					Selected_Figure->SetSelected(true);
	  					Selected_Figure->PrintInfo(pOut);
	  					return Selected_Figure;
	  				}
	  
	  
	  			}
	  
	  		}
	  
	  	
	  }
	  
	  	              // if the point dosen't belong to any figure
	  
	  	pOut->PrintMessage(" No selected figure ");           
	  
	  	//Add your code here to search for a figure given a point x,y	
	  //	//Remember that ApplicationManager only calls functions do NOT implement it.
	  //
	  	return NULL;
	  }
  */







			//if (FigList[i]->IsSelected())                 /// check any figure is selected
			//{
			//	FigList[i]->SetSelected(false);          // case selected before  un select it
			//	return NULL;
			//}
			//else                                         // case unselected before select it
			//{
			//	FigList[i]->SetSelected(true);
			//}

			//int k = 0;
			//while (k != FigCount)                       // to validate multiply selection 
			//{
			//	if (FigList[k] != FigList[i])
			//	{
			//		FigList[k]->SetSelected(false);
			//	}
			//	k++;
			//}

			//return FigList[i];
  int ApplicationManager::get_numofcolor(color c)
  {
	  int num = 0;
	  for (int i = 0; i < FigCount; i++)
	  {
		  if (FigList[i]->get_fillcolor() == c)
			  num++;
	  }
	  return num;
  }
  int ApplicationManager::numof_figurewithcolor(figures fig, colors c)
  {
	  CFigure* check_fig;
	  int n = 0;
	  switch (fig)
	  {
	  case squr:
		  for (int i = 0; i < FigCount; i++)
		  {
			  if (dynamic_cast<CSquare*>(FigList[i]))
				  if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					  n++;
		  }
		  break;
	  case rect:
		  for (int i = 0; i < FigCount; i++)
		  {
			  if (dynamic_cast<CRectangle*>(FigList[i]))
				  if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					  n++;
		  }
		  break;
	  case circ:
		  for (int i = 0; i < FigCount; i++)
		  {
			  if (dynamic_cast<CCircle*>(FigList[i]))
				  if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					  n++;
		  }
		  break;
	  case tria:
		  for (int i = 0; i < FigCount; i++)
		  {
			  if (dynamic_cast<CTriangle*>(FigList[i]))
				  if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					  n++;
		  }
		  break;
	  case hexa:
		  for (int i = 0; i < FigCount; i++)
		  {
			  if (dynamic_cast<CHexa*>(FigList[i]))
				  if (FigList[i]->get_fillcolor() == get_fillcolor(c))
					  n++;
		  }
		  break;
	  default:
		  break;
	  }
	  return n;
  }
  color ApplicationManager::get_fillcolor(colors c)
  {
	  switch (c)
	  {
	  case black:
		  return BLACK;
	  case red:
		  return RED;
	  case blue:
		  return BLUE;
	  case green:
		  return GREEN;
	  case yellow:
		  return YELLOW;
	  case orange:
		  return ORANGE;
	  default:
		  break;
	  }
  }
  string ApplicationManager::color_TO_String(colors c)
  {
	  switch (c)
	  {
	  case black:
		  return "black";
	  case red:
		  return "red";
	  case blue:
		  return "blue";
	  case green:
		  return "green";
	  case yellow:
		  return "yellow";
	  case orange:
		  return "orang";
	  default:
		  break;
	  }
  }
  string ApplicationManager::figur_TO_String(figures fig)
  {
	  switch (fig)
	  {
	  case squr:
		  return "square";
	  case rect:
		  return "rectangle";
	  case circ:
		  return "circle";
	  case tria:
		  return "triangle";
	  case hexa:
		  return "hexagine";
	  default:
		  break;
	  }
  }





