#include "CTriangle.h"
#include <sstream>
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
	id = ID;
	ID++;

}
CTriangle::CTriangle() {  };

int CTriangle::Getid()
{
	return id;
}

Point& CTriangle::GetP1()
{

	Point* p = new Point;
	*p = { (P1.x + P2.x + P3.x) / 3, (P1.y + P2.y + P3.y) / 3 };
	return *p;


}



void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawrtriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, FigGfxInfo, Selected);
}
bool CTriangle::checkselection(int x, int y)
{
	//int x1 = P1.x;	int x2 = P2.x;	int x3 = P3.x;
	//int y1 = P1.y;	int y2 = P2.y;	int y3 = P3.y;

	//int a1 = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	//int a2 = abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2);
	//int a3 = abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2);
	//int a4 = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2);
	//if (a1 == a2 + a3 + a4)
	//	return true;

	//return false;

	int x1 = P1.x;	int x2 = P2.x;	int x3 = P3.x;
	int y1 = P1.y;	int y2 = P2.y;	int y3 = P3.y;

	double denominator = ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	double a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denominator;
	double b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denominator;
	double c = 1 - a - b;

	if (a >= 0 && b >= 0 && c >= 0)
		return true;

	return false;


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
	this->id = stoi(datum[1]);
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

void CTriangle::move(const Point& newPos)
{
	P2 = P2 + newPos - P1;
	P3 = P3 + newPos - P1;
	P1 = newPos;
}

bool CTriangle::isInsideWindowBoundaries(const Point& newPos) const
{
	Point tP1, tP2, tP3;
	tP2 = tP2 + newPos - tP1;
	tP3 = tP3 + newPos - tP1;
	tP1 = newPos;
	if ((tP1.y) < (UI.ToolBarHeight + 5) || (tP2.y) < (UI.ToolBarHeight + 5) || (tP3.y) < (UI.ToolBarHeight + 5) || (tP1.y) > (UI.height - UI.StatusBarHeight + 5) || (tP2.y) > (UI.height - UI.StatusBarHeight + 5) || (tP3.y) > (UI.height - UI.StatusBarHeight + 5))
		return false;
	return true;
}


ostream& operator<<(ostream& op, const CTriangle& Fig) {
	op << Fig.id << " " << Fig.P1 << " " << Fig.P2 << " " << Fig.P3 << " " << " " << Fig.FigGfxInfo << endl;
	return op;
}
void CTriangle::PrintInfo(Output* pOut)
{

	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting

	string printed = "Fiure is Triangle      Figure id : " + to_string(id) +
		"        Fisrt Corner :(" + to_string(P1.x) + "," + to_string(P1.y) + ")"
		+ "        Second Corner :(" + to_string(P2.x) + "," + to_string(P2.y) + ")"
		+ "        Third Corner :(" + to_string(P3.x) + "," + to_string(P3.y) + ")";
	pOut->PrintMessage(printed);

}
color CTriangle::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}

