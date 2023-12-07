#pragma once
#include "CFigure.h"
class CSquare :
	public CFigure
{
private:
	Point P1, P2;
public:
    CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo);
    virtual void Draw(Output* pOut) const;
	CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CSquare&);
	void Save(fstream&)const;
	void Load(string&);
	bool checkselection(int x, int y);
	//  void PrintInfo(Output* pOut);




};

