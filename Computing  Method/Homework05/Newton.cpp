#include<iostream>
#include<math.h>
using namespace std;
double e=1.0e-8;
double f(double x);
double f_1(double x);
int main()
{
	double x=0,x_t[4]={0.1,0.2,0.9,9.0},x_c, y_t[4] = { 0.1,0.2,0.9,9.0 };
	for(int i=0;i<=3;i++)
	{
		int k=0;
		do
		{
			x_c = x;
			x=x_t[i]-f(x_t[i])/f_1(x_t[i]);
			x_t[i]=x;
			k++;
		} while (fabs(x - x_c) > e);
		cout<<y_t[i]<<" "<<x<<" "<<k<<endl;
	}
	system("pause");
}
double f(double x)
{
    return(pow(x,3)/3-x);
}
double f_1(double x)
{
	return(pow(x,2)-1);
}