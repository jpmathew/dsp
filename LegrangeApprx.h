#ifndef LEGRANGEAPPRX_H
#define LEGRANGEAPPRX_H
class LegrangeApprx
{
	private:
		float *x;
		float *y;
		int numPoints;
		float *w;
	public:
		LegrangeApprx(float *x,float *y,int numPoints)
		{
			int count,count1;
			this->x=x;
			this->y=y;
			this->numPoints=numPoints;
			w= new double[numPoints];
			for(count=0;count<numPoints;count++)
			{
				w[count]=1;
				for(count1=0;count1<numPoints;count1++)
				{
					if(count==count1)
					{
						continue;
					}
					else
					{
						w[count]*=(x[count]-x[count1]);
					}
				}
			}
		}
		double abs(double x)
		{
			return x>0?x:(-1*x);
		}
		double value(double xval)
		{
			double num,den,com;
			int count,count1;
			num=0;
			den=0;
			for(count=0;count<numPoints;count++)
			{
				if(abs(xval-x[count])<1e-10)
				{
					return y[count];
				}
				com=1/(w[count]*(xval-x[count]));
				num+=com*y[count];
				den+=com;
			}
			return num/den;
		}
};
#endif

