#include<math.h>
#include<iostream>
#include<stdlib.h>
void create(double v[], int N);
double cal_1(double v[], int m);
double cal_2(double v[], int m);
double f(double x);

int main()
{
	


	printf("Input the n");

	double a = cos(1) - cos(5);
	double *p_1;
	double x_1[13], x_2[13];
	x_1[0] = 0;
	x_2[0] = 0;
	p_1 = (double *)malloc(pow(2, 12) * sizeof(double));
	for (int i = 1;i <= 12;i++)
	{
		int m = pow(2, i);
		create(p_1, m);
		x_1[i] = cal_1(p_1, m);
		x_2[i]= cal_2(p_1, m);
		printf("For k=%d\n", i);
		printf("The first method gives %.15lf \n",x_1[i] );
		printf("The EOF is %.15lf\n", fabs(x_1[i] - a));
		printf("The order of EOF is %.15lf \n\n",log( fabs(x_1[i] - a)/fabs(x_1[i-1]-a))/log(2.0));
		printf("The second method gives %.15lf \n",x_2[i]);
		printf("The EOF is %.15lf \n", fabs(x_2[i] - a));
		printf("The order of EOF is %.15lf \n\n", log(fabs(x_2[i] - a) / fabs(x_2[i - 1] - a)) / log(2.0));
		printf("--------------------------------------------------\n\n");
	}
	free(p_1);
	system("pause");
}
void create(double v[],int N)
{
	
	for (int i = 0;i <= N;i++)
	{
		v[i] = (4.0 / (double)N)*i + 1.0;
	}
}
double cal_1(double v[],int m)
{
	double temp=0.5*(f(1.0)+f(5.0));
	for (int i = 1;i <= m;i++)
	{
		temp += f(v[i]);
	}
	return((4.0 / (double)m)*temp);
}
double cal_2(double v[], int m)
{
	double temp = f(1.0) + f(5.0)+ 4*f(v[1]);
	for (int i = 1;i <= m /2-1;i++)
	{
		temp += 4*f(v[2*i+1])+2*f(v[2*i]);
	}
	return((4.0 / (double)m)*temp/3);
}
double f(double x)
{
	return(sin(x));
}