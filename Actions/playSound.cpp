#include "playSound.h"
#include <Mmsystem.h>
#include <mciapi.h>
#include "../CMUgraphicsLib/auxil.h"
#include "../DEFS.h"
#pragma comment(lib, "Winmm.lib")

playSound::playSound(ApplicationManager* pApp, ActionType act) :Action(pApp), act(act)
{
	Execute();

}

void playSound::ReadActionParameters()
{
}

void playSound::Execute()
{
	switch (act) {
	case DRAW_RECT:
		PlaySound(".\\sounds\\rectangle.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case DRAW_CIRC:
		PlaySound(".\\sounds\\circle.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case DRAW_TRIA:
		PlaySound(".\\sounds\\triangle.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case DRAW_SQUA:
		PlaySound(".\\sounds\\Square.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;
	case DRAW_HEXA:
		PlaySound(".\\sounds\\hexagon.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case FUNC_SELECT:
		PlaySound(".\\sounds\\select.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case ENTER_PLAY_MODE:
		PlaySound(".\\sounds\\enterplaymode.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case FUNC_FILL:
		PlaySound(".\\sounds\\setfilcolor.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;

	case FUNC_BRUSH:
		PlaySound(".\\sounds\\setpencolor.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;
	case FUNC_MOVE:
		PlaySound(".\\sounds\\move.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;
	}
}
