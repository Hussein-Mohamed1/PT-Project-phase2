#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int DeletedFigCount;

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* Selected_Figure;

	CFigure* DeletedFigList[MaxFigCount];



	




	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	ApplicationManager(); 
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);  //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
	void set_figure(CFigure*);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() ;	//Redraws all the drawing window	
	void SaveAll(fstream &) const;
	 CFigure* GetSelected_Figure();
	 void DeleteFunction();
	 void SetSelectedFig(CFigure* S);
	 void DeleteFunctionForPlayMood(CFigure* Del);
	 void CopyDeletedFigToFiglist();
	 void AddDeletedFig(CFigure* del);
	// void DeleteFigure(CFigure* Del);
	 //bool Select(CFigure* figure);
	 //CFigure* GetFigureByPoint(int x, int y);
	 int get_numofcolor(color );
	 int numof_figurewithcolor(figures, colors);
	 color get_fillcolor(colors);
	 string color_TO_String(colors c);
	 string figur_TO_String(figures);
};


#endif