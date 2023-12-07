#include "CRectangle.h"
#include <sstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID++;
}

CRectangle::CRectangle() {};
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}}
ostream& operator<<(ostream& op, const CRectangle& Fig) {
	op << Fig.ID << " " << Fig.Corner1 << " " << Fig.Corner2 << " " << Fig.FigGfxInfo << endl;
	return op;
};
void CRectangle::Save(fstream& op) const
{
	op << "Rectangle: " << *this << endl;
}

void CRectangle::Load(string& line)
{
	SetSelected(0);

	/* Some Constants used to save shapes' info */
	const int NoOfSpaces = 14;

	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces]; // increased the size to accommodate maximum possible data fields

	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->Corner1.x = stoi(datum[2]);
	this->Corner1.y = stoi(datum[3]);
	this->Corner2.x = stoi(datum[4]);
	this->Corner2.y = stoi(datum[5]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);
}
bool CRectangle::checkselection(int x, int y)
{
	if ((x >= Corner1.x && x <= Corner2.x) && (y >= Corner1.y && y <= Corner2.y))
	{
		return true;
	}
	if ((x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y))
	{
		return true;
	}
	if ((x >= Corner1.x && x <= Corner2.x) && (y <= Corner1.y && y >= Corner2.y))
	{
		return true;
	}

	if ((x <= Corner1.x && x >= Corner2.x) && (y <= Corner1.y && y >= Corner2.y))
	{
		return true;
	}



	return false;

}



