#pragma once
#include "CFigure.h"
#include "fstream"
class CCircle : public CFigure
{
private:
	Point P1, P2;
	static int numofcirc;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	bool checkselection(int x, int y);
	void Save(fstream&) const;
	void Load(string&);
	friend ostream& operator<<(ostream&, const CCircle&);
	static int get_numofshape();

};


