#include "CSquare.h"
#include "sstream"
CSquare::CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	ID++;

}
CSquare::CSquare() {};
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawRect(P1, P2, FigGfxInfo, Selected);
}
void CSquare::Save(fstream& op) const
{

	op << "Square: " << *this << endl;
}
void CSquare::Load(string& line)
{
	SetSelected(0);
	const int NoOfSpaces = 14;

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
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);

}

ostream& operator<<(ostream& op, const CSquare& Fig) {
	op << Fig.ID << " " << Fig.P1 << " " << Fig.P2 << " " << Fig.FigGfxInfo << endl;
	return op;
};
bool CSquare::checkselection(int x, int y)
{
	if ((x >= P1.x && x <= P2.x) && (y >= P1.y && y <= P2.y))
	{
		return true;
	}
	return false;

}
