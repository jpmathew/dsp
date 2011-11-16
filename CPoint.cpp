#include "CPoint.h"

CPoint::CPoint()
{
	x=0;
	y=0;
}
CPoint::CPoint(int x,int y)
{
	this->x=x;
	this->y=y;
}
CPoint::CPoint(const CPoint& orig)
{
	this->x= orig.x;
	this->y= orig.y;
}
CPoint& CPoint::operator=(const CPoint &orig)
{
	this->x= orig.x;
	this->y= orig.y;
	return *this;
}
void CPoint::print()
{
	cout<<"x = "<<x<<" & y = "<<y<<endl;	
}

