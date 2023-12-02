#include "CCircle.h"

CCircle::CCircle(Point p1,  Point p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a circle  on the screen	
	pOut->DrawCirc(P1,P2, FigGfxInfo, Selected);

}
