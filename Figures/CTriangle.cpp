#include "CTriangle.h"
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure( FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
}
void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, FigGfxInfo, Selected);
}
bool CTriangle::checkselection(int x, int y)
{
	int x2 = P2.x;	int x1 = P1.x;	int x3 = P3.x;
	int y2 = P2.y;	int y1 = P1.y;	int y3 = P3.y;

	int a1 =abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	int a2 =abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2.0);
	int a3 =abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2.0);
	int a4 = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2.0);
	if (a1 == a2 + a3 + a4)
	{
		Selected = true;
		return true;
	}


	return false;
}
