#pragma once
#include "CFigure.h"
class CHexa : public CFigure
{
private:
	Point centre;
	int id;
	int l;  //side lenght of Hexa
	static int numofhexa;
public:

	CHexa(Point c, GfxInfo FigureGfxInfo);
	CHexa();

	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CHexa&);
	void Save(fstream&)const;
	void Load(string&);
	bool  checkselection(int x, int y);
	bool isInsideBoundaries(const Point&) const;
	void move(const Point&);
	int Getid();
	Point&  GetP1();
	
	void PrintInfo(Output* pOut);
	static int get_numofshape();
	//	void PrintInfo(Output* pOut);
	color get_fillcolor();

};

