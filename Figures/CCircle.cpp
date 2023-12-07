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
bool CCircle::checkselection(int x, int y)
{
	int Cicle_radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	int Given_radius= sqrt((P1.x - x) * (P1.x - x) + (P1.y - y) * (P1.y - y));
	if (Cicle_radius >= Given_radius)
	{
		Selected = true;
		return true;
	}
	return false;
}
