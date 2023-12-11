#pragma once
#include "CFigure.h"
#include "fstream"
class CCircle : public CFigure
{
private:
	Point P1, P2;

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool checkselection(int x, int y);
	void Save(fstream&) const;
	void Load(string&);
	friend ostream& operator<<(ostream&, const CCircle&);

};


