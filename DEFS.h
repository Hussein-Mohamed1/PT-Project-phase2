#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Recangle item in menu
	DRAW_CIRC,
	DRAW_TRIA,
	DRAW_SQUA,
	DRAW_HEXA,
	FUNC_ADD_IMAGE,
	FUNC_SELECT,
	FUNC_DELETE,
	COLOR_BLACK,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_ORANGE,
	FUNC_UNDO,
	FUNC_REDO,
	FUNC_START_REC,
	FUNC_PLAY_REC,
	FUNC_STOP_REC,
	FUNC_SAVE,
	FUNC_LOAD,
	ENTER_PLAY_MODE,
	FUNC_FILL,
	FUNC_MOVE,
	FUNC_CLEAR_CANVAS,
	FUNC_EXIT,
	FUNC_EXIT_playMode,
	DRAWING_AREA,
	STATUS,
	EMPTY,
	ENTER_DRAW_MODE,
	BY_COLOR,
	BY_SHAPE,
	BY_COLOR_SHAPE
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif