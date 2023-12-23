#pragma once
#include "CFigure.h"
#include "fstream"
class CCircle : public CFigure
{
private:
	Point P1, P2;
	int id;

	static int numofcirc;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	Point&  GetP1();
	
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool checkselection(int x, int y);
	void Save(fstream&) const;
	void Load(string&);
	friend ostream& operator<<(ostream&, const CCircle&);
	void move(const Point&);
	bool isInsideBoundaries(const Point&) const;
	int Getid();
	void PrintInfo(Output* pOut);
	static int get_numofshape();
	color get_fillcolor();
};


