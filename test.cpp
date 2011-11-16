#include <iostream>
#include "LinkedList.h" 
#include "CPoint.h"
using namespace std;

int main()
{
	LinkedList<CPoint> myList;
	CPoint *mypoint = new CPoint(1,1);
	CPoint *retPoint;
	myList.addUnit(mypoint);
	retPoint=myList.getUnit(0);
	retPoint=0;
	cout<<retPoint->x<<endl;
	return(0);
}
