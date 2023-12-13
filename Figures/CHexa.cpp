#include "CHexa.h"
#include "sstream"
CHexa::CHexa(Point c, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	centre = c;
	ID++;

}

void CHexa::Draw(Output* pOut) const
{
	int xc = centre.x, yc = centre.y;
	int l = 80;
	int small_height = l * 0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };

	pOut->Drawhexagon(xcoordiantes, ycoordinates, FigGfxInfo, Selected);

}
CFigure* CHexa::checkselection(int x, int y)
{
	int dis = sqrt((x - centre.x) * (x - centre.x) + (y - centre.y) * (y - centre.y));
	if (dis <= 80)   // you must change it if you change lenght of Hexa to be finaly  l;
	{
		return this;
	}
	return nullptr;
}

bool CHexa::isInsideBoundaries(const Point& newPos) const {
	Point tCentre = newPos;
	if ((newPos.y) - 80 < (UI.ToolBarHeight + 5) || (newPos.y) + 61 > (UI.height - UI.StatusBarHeight + 5)
		|| ((newPos.x) + 80) > (UI.width - 5) || (newPos.x) - 80 < 0) return 0;
	return 1;
}
void CHexa::move(const Point& newPos)
{
	centre = newPos;
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