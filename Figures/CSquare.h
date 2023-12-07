#pragma once
#include "CFigure.h"
class CSquare :
    public CFigure
{
private:
    Point P1, P2;
public:
    CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo);
    virtual void Draw(Output* pOut) const;
    bool checkselection(int x, int y);


};

