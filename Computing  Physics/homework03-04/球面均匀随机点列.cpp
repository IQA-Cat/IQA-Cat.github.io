#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void read(double v[],double u[],int N);
void scale_phi(double v[],int N);
void scale_theta(double v[],int N);
void output(double v[],double u[],int N);
int main()
{
	double *p_1;
	double *p_2;
	int N;
	scanf("%d",&N); 
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));//分配动态内存空间 
	read(p_1,p_2,N);//从文件中读取数据 
	scale_phi(p_1,N);
	scale_theta(p_2,N);
	output(p_2,p_1,N);
	free(p_1);
	free(p_2);
 } 
void read(double v[],double u[],int N)//读取函数 
{
	FILE *fp;
	fp=fopen("test.dat","r+");
	if(fp==NULL)
	{
		printf("NULL"); 
	}
	for(int i=1;i<=N;i++)
	{
		fscanf (fp,"%lf",&v[i]);
		fscanf (fp,"%lf",&u[i]);
	}

	fclose(fp);
}
void scale_phi(double v[],int N)//rescale 函数 
 {
 	for(int i=1;i<=N;i++)
 	{
		v[i]=(double)v[i]*2*3.1415926;
	}
 }
 void scale_theta(double v[],int N)//rescale 函数 
 {
 	for(int i=1;i<=N;i++)
 	{
		v[i]=acos(v[i]*2-1);
	}
 }
 void output(double v[],double u[],int N)//输出函数 
 {
 	FILE *fp;
	fp=fopen("sph.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=1;i<=N;i++)
	{
		fprintf(fp,"%lf %lf %lf\n",sin(v[i])*cos(u[i]),sin(v[i])*sin(u[i]),cos(v[i]));
	}
	fclose(fp);
 }
