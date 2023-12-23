#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}



buttonstate Input::GetButtonState(const button btMouse, int& iX, int& iY)
{
	return pWind->GetButtonState(btMouse, iX, iY);
}



string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "-1";	//returns -1 as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

void Input::FlushMouseQueue()
{
	pWind->FlushMouseQueue();
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[0] Clicked in Mini Color Bar  

			  /// Color Black      /// Color Red         // Color Blue 
		int start = 11 * UI.MenuItemWidth;
		int  k = 1;
		int space = 10;
		if (y <= 1 + UI.MiniColorHeight)
		{
			// Black 
			if (x >= start && x <= start + UI.MiniColorWidth)
			{
				return COLOR_BLACK;
			}
			//k++;

		  // Red 
			if (x >= start + UI.MiniColorWidth * k + k * space && x <= start + UI.MiniColorWidth * (k + 1) + space * k)
			{
				return COLOR_RED;
			}
			k++;
			if (x >= start + UI.MiniColorWidth * k + k * space && x <= start + UI.MiniColorWidth * (k + 1) + space * k)
			{
				return COLOR_BLUE;
			}

		}

		k = 1;
		//// Color yellow        Green                  Orange

		if (y <= 25 + UI.MiniColorHeight && y >= UI.MiniColorHeight)
		{
			// Black 
			if (x >= start && x <= start + UI.MiniColorWidth)
			{
				return COLOR_GREEN;
			}
			//k++;

		  // Red 
			if (x >= start + UI.MiniColorWidth * k + k * space && x <= start + UI.MiniColorWidth * (k + 1) + space * k)
			{
				return COLOR_YELLOW;
			}
			k++;
			if (x >= start + UI.MiniColorWidth * k + k * space && x <= start + UI.MiniColorWidth * (k + 1) + space * k)
			{
				return COLOR_ORANGE;
			}

		}





		///////Icons Before Colors

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRIA: return DRAW_TRIA;
			case ITM_SQUA: return DRAW_SQUA;
			case ITM_HEXA: return DRAW_HEXA;
			case ADD_IMAGE: return FUNC_ADD_IMAGE;
			case ITM_SELECT: return FUNC_SELECT;
			case ITM_DELETE: return FUNC_DELETE;
			//case ITM_BLACK: return COLOR_BLACK;
			//case ITM_RED: return COLOR_RED;
			//case ITM_BLUE: return COLOR_BLUE;
			//case ITM_GREEN: return COLOR_GREEN;
			//case ITM_YELLOW: return COLOR_YELLOW;
			//case ITM_ORANGE: return COLOR_ORANGE;
			//case ITM_UNDO: return FUNC_UNDO;
			//case ITM_REDO: return FUNC_REDO;
			//case ITM_START_REC: return FUNC_START_REC;
			//case ITM_PLAY_REC: return FUNC_PLAY_REC;
			//case ITM_STOP_REC: return FUNC_STOP_REC;
			//case ITM_SAVE: return FUNC_SAVE;
			//case ITM_LOAD: return FUNC_LOAD;
			//case PLAY_MODE: return ENTER_PLAY_MODE;
			case CLEAR_CANVAS: return FUNC_CLEAR_CANVAS;
			//case ITM_EXIT: return FUNC_EXIT;
			case ITM_FILL: return FUNC_FILL;
			case ITM_MOVE: return FUNC_MOVE;
			case ITM_BRUSH:return FUNC_BRUSH;


			}

			//  Icons After Colors
			start = UI.MenuItemWidth * 13 + 5;
			space = 1;
			k = 1;

			if (x >= start && x <= start + UI.MenuItemWidth)
				return FUNC_UNDO;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_REDO;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_START_REC;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_PLAY_REC;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_STOP_REC;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_SAVE;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_LOAD;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return ENTER_PLAY_MODE;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_CLEAR_CANVAS;
			k++;
			if (x >= start + UI.MenuItemWidth * k + k * space && x <= start + UI.MenuItemWidth * (k + 1) + space * k)
				return FUNC_EXIT;
			k++;

			return EMPTY;

		}


		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	if (y >= 0 && y < UI.ToolBarHeight && UI.InterfaceMode == MODE_PLAY)
	{
		//Check whick Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
		{
		case DRAW_MODE: return ENTER_DRAW_MODE;

		case byColor: return BY_COLOR;

		case byShape: return BY_SHAPE;

		case byColorShape: return BY_COLOR_SHAPE;

		case ITM_EXIT_playMode: return FUNC_EXIT_playMode;
		}

		//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
