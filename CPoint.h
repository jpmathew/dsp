#ifndef CPOINT_H
#define CPOINT_H
#include <iostream>
using namespace std;

class CPoint
{
	public:
	int x,y;
	CPoint(int x,int y)
	{
	 	this->x=x;
		this->y=y;
	}
	CPoint()
	{
		x=0;
		y=0;
	}
};

#endif
