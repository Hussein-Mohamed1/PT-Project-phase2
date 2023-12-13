#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CRectangle&);
	void Save(fstream&)const;
	void Load(string&);
	CFigure* checkselection(int x, int y);
	bool isInsideBoundaries(const Point&) const;
	bool checkselection(int x, int y);
	//void PrintInfo(Output* pOut);

};

#endif