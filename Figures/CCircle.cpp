#include "CCircle.h"
#include <fstream>
#include <sstream>
#include "cstring"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& op, const color& c) {
	op << int(c.ucRed) << " " << int(c.ucGreen) << " " << int(c.ucBlue);
	return op;
}
CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;

}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a circle  on the screen	
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);

}
CCircle::CCircle() {};

ostream& operator<<(ostream& op, const CCircle& c)
{
	op << c.ID << " " << c.P1 << " " << c.P2 << " " << c.FigGfxInfo << endl;
	return op;
}


void CCircle::Save(fstream& op) const {
	op << "Circle: " << *this << endl;
}
void CCircle::Load(string& line)
{

	/* Some Constants used to save shapes' info */
	const int NoOfSpaces = 14;


	stringstream ss(line); // string stream is used as it splits the line based on white spaces
	string temp;
	string datum[14]; // increased the size to accommodate maximum possible data fields


	for (int i = 0; i < 14; i++) {
		ss >> datum[i];
	}
	SetSelected(0);
	this->P1.x = stoi(datum[2]);
	this->P1.y = stoi(datum[3]);
	this->P2.x = stoi(datum[4]);
	this->P2.y = stoi(datum[5]);
	this->FigGfxInfo.DrawClr = color(stoi(datum[6]), stoi(datum[7]), stoi(datum[8]));
	this->FigGfxInfo.FillClr = color(stoi(datum[9]), stoi(datum[10]), stoi(datum[11]));
	this->FigGfxInfo.isFilled = stoi(datum[12]);
	this->FigGfxInfo.BorderWdth = stoi(datum[13]);



}
bool CCircle::checkselection(int x, int y)
{
	int Cicle_radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	int Given_radius = sqrt((P1.x - x) * (P1.x - x) + (P1.y - y) * (P1.y - y));
	if (Cicle_radius >= Given_radius)
	{
		return true;
	}
	return false;
}

;
