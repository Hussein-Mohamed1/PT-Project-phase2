#include "CTriangle.h"
#include <sstream>
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	ID++;

}
CTriangle::CTriangle() {};
void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, FigGfxInfo, Selected);
}
