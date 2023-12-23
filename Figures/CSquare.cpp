#include "CSquare.h"
#include "sstream"
CSquare::CSquare(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	P1 = p1;
	P2 = p2;
	id = ID;
	ID++;

}


int CSquare::Getid()
{
	return id;
}

Point& CSquare::GetP1()
{
	return (P1+P2)/2;
}


CSquare::CSquare() { numofsquare++; };
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

void CSquare::move(const Point& newPos)
{
	Point Center = (P2 + P1) / 2;
	P2 = newPos + P2 - Center;
	P1 = newPos + P1 - Center;
}

bool CSquare::isInsideBoundaries(const Point& newPos) const
{

	Point P2 = newPos + CSquare::P2 - (CSquare::P2 + CSquare::P1) / 2;
	Point P1 = newPos + CSquare::P1 - (CSquare::P2 + CSquare::P1) / 2;
	if ((!(P1.y > UI.ToolBarHeight + 5 && P1.y < UI.height - UI.StatusBarHeight - 5)) || (!(P2.y > UI.ToolBarHeight + 5 && P2.y < UI.height - UI.StatusBarHeight - 5)) || (P1.x < 5 || P2.x >= UI.width - 5))
		return 0;
	return 1;
}
void CSquare::PrintInfo(Output* pOut)
{
	int hieght = abs(P1.y - P2.y);

	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting

	string printed="Fiure is Square      Figure id : "+ to_string(id)+
		"        Fisrt Corner :(" + to_string(P1.x) + "," + to_string(P1.y) + ")"
		+ "        Second Corner :(" + to_string(P2.x) + "," + to_string(P2.y) + ")"
		+ "        height " + to_string(hieght) + "        width " + to_string(hieght);   // hieght = widght becuase it's a square

	pOut->PrintMessage(printed);

}
color CSquare::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}
