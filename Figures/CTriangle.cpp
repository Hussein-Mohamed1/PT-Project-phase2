#include "CTriangle.h"
#include <sstream>
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
}
CTriangle::CTriangle() {};
void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, FigGfxInfo, Selected);
}
void CTriangle::Save(fstream& op) const
{
	op << "Triangle: " << *this << endl;
}
void CTriangle::Load(string& line)
{
	SetSelected(0);
	const int NoOfSpaces = 16;


	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces]; // increased the size to accommodate maximum possible data fields

	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->P1.x = stoi(datum[2]);
	this->P1.y = stoi(datum[3]);
	this->P2.x = stoi(datum[4]);
	this->P2.y = stoi(datum[5]);
	this->P3.x = stoi(datum[6]);
	this->P3.y = stoi(datum[7]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[8]), stoi(datum[9]), stoi(datum[10]));
	this->FigGfxInfo.FillClr = color(stoi(datum[11]), stoi(datum[12]), stoi(datum[13]));
	this->FigGfxInfo.isFilled = (unsigned int)stoi(datum[14]);
	this->FigGfxInfo.BorderWdth = (unsigned int)stoi(datum[15]);
}


ostream& operator<<(ostream& op, const CTriangle& Fig) {
	op << Fig.ID << " " << Fig.P1 << " " << Fig.P2 << " " << Fig.P3 << " " << " " << Fig.FigGfxInfo << endl;
	return op;
};