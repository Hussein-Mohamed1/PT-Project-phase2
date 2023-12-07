#pragma once
#include "CFigure.h"

class CTriangle :
    public CFigure
{
private:
    Point P1, P2, P3;
public:

    CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);
    CTriangle();
    virtual void Draw(Output* pOut) const;
    void Save(fstream&)const;
    friend ostream& operator<<(ostream&, const CTriangle&);
    void Load(string &);
};
