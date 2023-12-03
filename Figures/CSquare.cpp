#include "CSquare.h"

CSquare::CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawRect(P1, P2, FigGfxInfo, Selected);
}
