#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void read(double v[],double u[],int N);
void scale(double v[],int N);
void output(double v[],double u[],int N);
void test(double v[],double u[],double t[],double w[],int N);
int j=0;
int main()
{
	double *p_1;
	double *p_2;
	double *p_3;
	double *p_4;
	int N;
	scanf("%d",&N); 
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));
	p_3=(double *)malloc(N*sizeof(double));
	p_4=(double *)malloc(N*sizeof(double));//分配动态内存空间 
	read(p_1,p_2,N);//从文件中读取数据 
	scale(p_1,N);
	scale(p_2,N);
	test(p_1,p_2,p_3,p_4,N);
	output(p_3,p_4,j);
	free(p_1);
	free(p_2);
	free(p_3);
	free(p_4);
	
 } 
void test(double v[],double u[],double t[],double w[],int N)
{
	for(int i=1;i<=N;i++)
	{
		if(v[i]*v[i]+u[i]*u[i]<=1)
		{
			t[j]=v[i],w[j]=u[i];
			j++;
		}
	}
	printf("j=%d\n",j);
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

void scale(double v[],int N)//rescale 函数 
 {
 	for(int i=1;i<=N;i++)
 	{
		v[i]=v[i]*2-1;
	}
 }
 void output(double v[],double u[],int N)//输出函数 
 {
 	FILE *fp;
	fp=fopen("Marsaglia.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=1;i<=N;i++)
	{
		fprintf(fp,"%lf %lf\n",2*u[i]*sqrt(1-(u[i]*u[i]+v[i]*v[i])),2*v[i]*sqrt(1-(u[i]*u[i]+v[i]*v[i])));
	}
	fclose(fp);
 }
