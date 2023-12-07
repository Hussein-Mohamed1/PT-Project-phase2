#include "CHexa.h"

CHexa::CHexa( Point c,GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centre = c;
}

void CHexa::Draw(Output* pOut) const
{
    int xc = centre.x, yc = centre.y;
	int l = 80;
	int small_height = l *0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };

	pOut->Drawhexagon(xcoordiantes, ycoordinates, FigGfxInfo);

}
bool CHexa::checkselection(int x, int y)
{
	int dis = sqrt((x - centre.x)* (x - centre.x) + (y - centre.y) * (y - centre.y));
	if (dis <= 80)   // you must change it if you change lenght of Hexa to be finaly  l;
	{
		Selected = true;
		return true;
	}
	return false;
}