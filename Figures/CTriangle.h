#pragma once
#include "CFigure.h"
class CTriangle :
    public CFigure
{
private:
    Point P1, P2, P3;
public:

    CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);
    virtual void Draw(Output* pOut) const;
    bool checkselection(int x, int y);

};

