#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	static int numofrect;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CRectangle&);
	void Save(fstream&)const;
	void Load(string&);
	static int get_numofshape();
	bool checkselection(int x, int y);
	//void PrintInfo(Output* pOut);

};

#endif