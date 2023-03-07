#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void read(double v[],double u[],int N);
void scale_phi(double v[],double u[],int N);
void scale_theta(double v[],int N);
void output(double v[],double u[],int N);
void choose(double v[],double u[],double t[],double s[],int N);
void count(double v[],int j,int u[]);
 void output_2(int u[]);
int j;
int main()
{
	double *p_1;
	double *p_2;
	double *p_3;
	double *p_4;
	int *p_i;
	int N;
	scanf("%d",&N); 
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));
	p_3=(double *)malloc(N*sizeof(double));
	p_4=(double *)malloc(N*sizeof(double));
	p_i=(int *)malloc(601*sizeof(int));//分配动态内存空间 
	read(p_1,p_2,N);//从文件中读取数据 
	scale_phi(p_1,p_2,N);
	choose(p_1,p_2,p_3,p_4,N);
	count(p_3,j,p_i);
	output(p_3,p_4,j);
	output_2(p_i);
	free(p_1);
	free(p_2);
	free(p_3);
	free(p_4);
	free(p_i);
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
void scale_phi(double v[],double u[],int N)//rescale 函数 
 {
 	for(int i=1;i<=N;i++)
 	{
		v[i]=tan(3.1415926535/2*(2*v[i]-1.0));
		u[i]=2*u[i]/(3.1415926535*(1+v[i]*v[i]));
	}
 }
 void choose(double v[],double u[],double t[],double s[],int N)
 {
 	j=0;
 	for(int i=1;i<=N;i++)
 	{
 		if(u[i]<=(1/sqrt(2*3.1415926535)*pow(2.71828,-v[i]*v[i]/2)))
 		{
		t[j]=v[i];
 		s[j]=u[i];
 		j++;
 		}
	 }
 }
 void output(double v[],double u[],int N)//输出函数 
 {
 	FILE *fp;
	fp=fopen("p.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=1;i<=N;i++)
	{
		fprintf(fp,"%lf %lf\n",v[i],u[i]);
	}
	printf("j=%d\n",j);
	fclose(fp);
 }
 void count(double v[],int M,int u[])
 {
 	for(int i=0;i<=600;i++)
 	{
 		u[i]=0;
 		for(int k=1;k<=M;k++)
 		{
 			if((v[k]>(-3+0.01*i))&&(v[k]<(-3+0.01*(i+1))))
 			{
 				u[i]=u[i]+1;
			}
		}
	 }
 }
 void output_2(int u[])
 {
 	FILE *fp;
	fp=fopen("p-2.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=0;i<=600;i++)
	{
		fprintf(fp,"%lf %lf\n",-3+0.01*i+0.005,(double)u[i]*100/j);
	}
	fclose(fp);
 }
