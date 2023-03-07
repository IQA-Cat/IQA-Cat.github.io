#include<math.h>
#include<stdlib.h>
#include<stdio.h>
double interation(double v[], int N, double L);
void slide_L(double v[], double u[], int N, int K, double L);
void out(double v[], int N, double L);
void main()
{
	double L;
	printf("Please input L:");
	scanf_s("%lf", &L);
	int N;
	printf("Please input N:");
	scanf_s("%d", &N);
	int K;
	printf("Please input K:");
	scanf_s("%d", &K);
	double *p;
	p = (double *)malloc(K * sizeof(double));
	double *m;
	m = (double *)malloc(N * sizeof(double));
	slide_L(m, p, N, K,L);
	out(m,N, L);
	free(m);
	free(p);
}
double interation(double v[],int K,double L)
{
	v[0] = 1;
	for (int i = 0;i <= K-1;i++)
	{
		v[i + 1] = L*sin(3.1415926*v[i]);
	}
	return(v[K]);
}
void slide_L(double v[],double u[], int N,int K,double L)
{
	for (int i = 1;i <= N;i++)
	{
		v[i] = interation(u, K, (double)i*L/(double)N);
	}
}
void out(double v[],int N,double L)
{
	FILE *fp;
	fopen_s(&fp,"test2.dat", "w");
	if (fp == NULL)
	{
		printf("false");
	}
	for (int i = 1;i <= N;i++)
	{
		fprintf(fp, "%lf %lf\n", (double)i*L / (double)N, v[i]);
	}
	fclose(fp);
}