#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	int id;
	static int numofrect;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	void move(const Point& newPos);

	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CRectangle&);
	void Save(fstream&)const;
	void Load(string&);
	bool isInsideBoundaries(const Point&) const;
	bool checkselection(int x, int y);
	int Getid();

	void PrintInfo(Output* pOut);
	static int get_numofshape();
	color get_fillcolor();
	//void PrintInfo(Output* pOut);

};

#endif