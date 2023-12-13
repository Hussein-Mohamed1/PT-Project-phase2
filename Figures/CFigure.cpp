#include "CFigure.h"

int CFigure:: ID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure() {}

void CFigure::SetSelected(bool s)
{
	Selected = s;
	
}

bool CFigure::IsSelected() const
{
	return Selected;
}

//void CFigure::ChngDrawClr(color Dclr)
//{
//	FigGfxInfo.DrawClr = Dclr;
//}
void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
ostream& operator<<(ostream& op, const Point& p) {
	op << p.x << " " << p.y;
	return op;
}


ostream& operator << (ostream& op, const GfxInfo& gfx) {
	op << gfx.DrawClr << " " << gfx.FillClr << " " << gfx.isFilled << " " << gfx.BorderWdth;
	return op;
};

