#pragma once
#include "CFigure.h"
class CSquare :
	public CFigure
{
private:
	Point P1, P2;
	int id;
	static int numofshapes;
public:
	CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CSquare&);
	void Save(fstream&)const;
	void Load(string&);
	void move(const Point&);
	bool isInsideWindowBoundaries(const Point&) const;
	bool checkselection(int x, int y);
	int Getid();
	Point& GetP1();

	void PrintInfo(Output* pOut);

	//  void PrintInfo(Output* pOut);
	color get_fillcolor();
	static int getnumofshapes();
	 void decrementnumofshapes();
	 bool is_filled();
	 ~CSquare();
};

