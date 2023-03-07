#include<iostream>
#include<math.h>
using namespace std;
double e = 1.0e-8;
double f(double x);
int main()
{
    double x=0,a[4]={-0.1,-0.2,-2.0,0.9},b[4]={0.1,0.2,0.9,9.0},x_1,x_2,x_t;
    for(int i=0;i<=3;i++)
    {
        int k=0;
        x_1=b[i],x_2=a[i];
        do
        {
            x_t=x;
            x=x_1-(f(x_1))*(x_1-x_2)/(f(x_1)-f(x_2));
			x_2 = x_1;
            x_1=x;
            k++;
        }while(fabs(x-x_t)>e);
        cout<<a[i]<<" "<<b[i]<<"    "<<x<<" "<<k<<endl;
    }
	system("pause");
}
double f(double x)
{
    return(pow(x,3)/3-x);
}
