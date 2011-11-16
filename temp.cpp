#include <iostream>
#include <fstream>
#include "LegrangeApprx.h"
#include <cmath>

using namespace std;

int main()
{
	double x[10],y[10];
	int count;
	const double pi=3.1415; 
	ofstream data;

	data.open("filt.dat",ios::out);

	x[0]=0.0;
	y[0]=1.05;
	x[1]=0.2*pi;
	y[1]=0.95;
	x[2]=0.4*pi;
	y[2]=0.05;
	x[3]=4.5*pi/8.0;
	y[3]=-0.05;
	x[4]=6.0*pi/8.0;
	y[4]=0.05;
	x[5]=7.0*pi/8.0;
	y[5]=-0.05;
	x[6]=7.6*pi/8.0;
	y[6]=0.05;

	LegrangeApprx myfunc(x,y,7);
	cout<<"fsdsdgsag"<<endl;
	for(count=0;count<7;count++)
	{
		cout<<x[count]<<"\t"<<myfunc.value(x[count]+0.05*pi)<<endl;
	}

	for(count=0;count<100;count++)
	{
		data<<myfunc.value(count*pi/100)<<endl;
	}
}


