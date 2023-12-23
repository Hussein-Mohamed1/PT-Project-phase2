#pragma once
#include "CFigure.h"

class CTriangle :
	public CFigure
{
private:
	Point P1, P2, P3;
	int id;
public:

	CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	bool checkselection(int x, int y);
	void Save(fstream&)const;
	friend ostream& operator<<(ostream&, const CTriangle&);
	void Load(string&);
	void move(const Point&);
	bool isInsideBoundaries(const Point&) const;
	int Getid();
	void PrintInfo(Output* pOut);
	color get_fillcolor();
};
