#pragma once
#include "CFigure.h"
class CSquare :
	public CFigure
{
private:
	Point P1, P2;
	int id;
	static int numofsquare;
public:
	CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CSquare&);
	void Save(fstream&)const;
	void Load(string&);
	void move(const Point&);
	bool isInsideBoundaries(const Point&) const;
	bool checkselection(int x, int y);
	int Getid();

	 void PrintInfo(Output* pOut);

	//  void PrintInfo(Output* pOut);
	static int get_numofshape();
	color get_fillcolor();


};

