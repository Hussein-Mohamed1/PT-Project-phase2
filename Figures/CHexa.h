#pragma once
#include "CFigure.h"
class CHexa : public CFigure 
{
private:
	Point centre;
public:

	CHexa( Point c ,GfxInfo FigureGfxInfo);

	void Draw(Output* pOut) const;

	bool  checkselection(int x, int y);
};

