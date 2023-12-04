#include "CHexa.h"

CHexa::CHexa( Point c,GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centre = c;
}

void CHexa::Draw(Output* pOut) const
{
	int xc = centre.x, yc = centre.y;

	int x8coordinates[8] = { xc + 61,xc + 43,xc , xc - 43,xc - 63,xc - 43,xc,xc + 43 };
	int y8coordinates[8] = { yc ,yc - 43,yc - 61 ,yc - 43,yc,yc + 43,yc + 63,yc + 43 };
	pOut->Drawhexagon(x8coordinates, y8coordinates, FigGfxInfo);

}