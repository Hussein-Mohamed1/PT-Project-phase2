#include "CSquare.h"

CSquare::CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	ID++;

}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawRect(P1, P2, FigGfxInfo, Selected);
}
bool CSquare::checkselection(int x, int y)
{
	if ((x >= P1.x && x <= P2.x) && (y >= P1.y && y <= P2.y))
	{
		return true;
	}
	return false;

}
