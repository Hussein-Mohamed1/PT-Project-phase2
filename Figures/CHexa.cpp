#include "CHexa.h"
#include "sstream"
CHexa::CHexa(Point c, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centre = c;
}

void CHexa::Draw(Output* pOut) const
{
	int xc = centre.x, yc = centre.y;

	int x8coordinates[8] = { xc + 61,xc + 43,xc , xc - 43,xc - 63,xc - 43,xc,xc + 43 };
	int y8coordinates[8] = { yc ,yc - 43,yc - 61 ,yc - 43,yc,yc + 43,yc + 63,yc + 43 };
	pOut->Drawhexagon(x8coordinates, y8coordinates, FigGfxInfo);

}
CHexa::CHexa() {};
void CHexa::Save(fstream& op) const
{

	op << "Hexagon: " << *this << endl;
}

void CHexa::Load(string& line)

{
	SetSelected(0);

	const int NoOfSpaces = 12; // increased the size to accommodate maximum possible data fields
	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[NoOfSpaces];


	for (int i = 0; i < NoOfSpaces; i++) {
		ss >> datum[i];
	}
	this->centre.x = stoi(datum[2]);
	this->centre.y = stoi(datum[3]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[4]), stoi(datum[5]), stoi(datum[6]));
	this->FigGfxInfo.FillClr = color(stoi(datum[7]), stoi(datum[8]), stoi(datum[9]));
	this->FigGfxInfo.isFilled = stoi(datum[10]);
	this->FigGfxInfo.BorderWdth = stoi(datum[11]);
}


ostream& operator<<(ostream& op, const CHexa& Fig) {
	op << Fig.ID << " " << Fig.centre << " " << Fig.FigGfxInfo << endl;
	return op;
};