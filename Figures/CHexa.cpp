#include "CHexa.h"
#include "sstream"
#include <sstream>
#include "cstring"
#include<iostream>
#include"string.h"
#include<algorithm>
using namespace std;
CHexa::CHexa(Point c, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), centre(c), id(ID++), l(80)      //Here , if you want to change side lenght of Hexa 

{
}
int CHexa::Getid()
{
	return id;
}

Point& CHexa::GetP1()
{
	return centre;
}



bool CHexa::checkselection(int x, int y)
{
	// approach one 
	// 
	//int dis = sqrt((x - centre.x) * (x - centre.x) + (y - centre.y) * (y - centre.y));
	//if (dis <=l-6)   // you must change it if you change lenght of Hexa to be finaly  l;
	//{
	//	return true;
	//}
	//return false;

	// approach two 

	int xc = centre.x, yc = centre.y;
	int small_height = l * 0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };


	int count = 0;
	for (int i = 0; i < 6; ++i) {
		int j = (i + 1) % 6;
		if ((ycoordinates[i] > y) != (ycoordinates[j] > y) &&
			x < (xcoordiantes[j] - xcoordiantes[i]) * (y - ycoordinates[i]) / (ycoordinates[j] - ycoordinates[i]) + xcoordiantes[i]) {
			count++;
		}
	}
	return count % 2 == 1;




}

void CHexa::Draw(Output* pOut) const
{
	int xc = centre.x, yc = centre.y;
	int small_height = l * 0.87;         // cos(60)  (from geometry of shape)
	int small_lenght = l * 0.5;       // sin(60) (from geometry of shape)
	int xcoordiantes[6] = { xc + l , xc + small_lenght,xc - small_lenght , xc - l , xc - small_lenght , xc + small_lenght };
	int ycoordinates[6] = { yc     , yc - small_height,yc - small_height , yc     , yc + small_height , yc + small_height };

	pOut->Drawhexagon(xcoordiantes, ycoordinates, FigGfxInfo, Selected);

}

bool CHexa::isInsideWindowBoundaries(const Point& newPos) const {
	Point tCentre = newPos;
	if ((newPos.y) - 80 < (UI.ToolBarHeight + UI.wx) || (newPos.y) + 61 > (UI.height - (UI.StatusBarHeight + UI.wx))
		|| ((newPos.x) + 80) > (UI.width - UI.wx) || (newPos.x) - 80 < 0) return 0;
	return 1;
}
void CHexa::move(const Point& newPos)
{
	centre = newPos;
}
CHexa::CHexa() : l(80) {  };
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
	this->id = stoi(datum[1]);
	this->centre.x = stoi(datum[2]);
	this->centre.y = stoi(datum[3]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[4]), stoi(datum[5]), stoi(datum[6]));
	this->FigGfxInfo.FillClr = color(stoi(datum[7]), stoi(datum[8]), stoi(datum[9]));
	this->FigGfxInfo.isFilled = stoi(datum[10]);
	this->FigGfxInfo.BorderWdth = stoi(datum[11]);
}


ostream& operator<<(ostream& op, const CHexa& Fig) {
	op << Fig.id << " " << Fig.centre << " " << Fig.FigGfxInfo << endl;
	return op;
};
void CHexa::PrintInfo(Output* pOut)
{
	// concatination to print one sting contaion all data of figure

	// to_string ()  is a function that cast int to strting
	string printed = " Figure is Hexa         Figure id : " + to_string(id) + "        Side lenght : " + to_string(l)
		+ "       Centre : (" + to_string(centre.x) + "," + to_string(centre.y) + ")";
	pOut->PrintMessage(printed);
}
color CHexa::get_fillcolor()
{
	return FigGfxInfo.FillClr;
}