#pragma once
#include "CFigure.h"
class CCircle : public CFigure
{
private: 
	Point P1, P2;
	
public:
	CCircle(Point, Point , GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool checkselection(int x, int y);
	void PrintInfo(Output* pOut);

};

