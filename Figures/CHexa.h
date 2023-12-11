#pragma once
#include "CFigure.h"
class CHexa : public CFigure
{
private:
	Point centre;
public:

	CHexa(Point c, GfxInfo FigureGfxInfo);
	CHexa();

	virtual void Draw(Output* pOut) const;
	friend ostream& operator<<(ostream&, const CHexa&);
	void Save(fstream&)const;
	void Load(string&);
	virtual bool  checkselection(int x, int y);

	//	void PrintInfo(Output* pOut);


};

