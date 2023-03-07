#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void read_1(double v[],double u[],int N);
void read_2(double v[],double u[],int N);
void scale_phi(double v[],double u[],int N);
void scale_theta(double v[],int N);
void output(double v[],double u[],int N);
 void choose(double v[],double u[],double t[],double s[],int N,double p[]);
void count(double v[],int j,int u[]);
 void output_2(int u[]);
int j;
int B=3010-2900;
int main()
{
	double *p_1;
	double *p_2;
	double *p_3;
	double *p_4;
	double *p_5;
	double *p_6;
	int *p_i;
	int N;
	scanf("%d",&N); 
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));
	p_3=(double *)malloc(N*sizeof(double));
	p_4=(double *)malloc(N*sizeof(double));
	p_5=(double *)malloc(N*sizeof(double));
	p_6=(double *)malloc(N*sizeof(double));
	p_i=(int *)malloc((B*100+1)*sizeof(int));//分配动态内存空间 
	read_1(p_1,p_2,N);
	read_2(p_5,p_6,B);//从文件中读取数据 
	scale_phi(p_1,p_2,N);	
	choose(p_1,p_2,p_3,p_4,N,p_6);
	count(p_3,j,p_i); 
	output(p_3,p_4,j);
	output_2(p_i);
	free(p_1);
	free(p_2);
	free(p_3);
	free(p_4);
	free(p_i);
	free(p_5);
	free(p_6);
 } 
void read_1(double v[],double u[],int N)//读取函数 
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
void read_2(double v[],double u[],int N)//读取函数 
{
	FILE *fp;
	fp=fopen("data.txt","r+");
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
		v[i]=(double)(3010-2900)*v[i]+2900.0;
		u[i]=2800*u[i];
	}
	for(int i=1;i<=N;i++)
	{
		if((v[i]>=2995)&&(v[i]<=3004))
		{
			u[i]*=(double)410/29;
		}
	}
 }
 void choose(double v[],double u[],double t[],double s[],int N,double p[])
 {
 	j=0;
 	for(int k=0;k<=B;k++)
 	{
 		for(int i=1;i<=N;i++)
 		{
 			if((u[i]<=p[k])&&(v[i]>2900+k)&&(v[i]<2900+k+1))
 			{
			t[j]=v[i];
 			s[j]=u[i];
 			j++;
 			}
		 }
	}
 }
 void output(double v[],double u[],int N)//输出函数 
 {
 	FILE *fp;
	fp=fopen("q.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=1;i<=N-1;i++)
	{
		fprintf(fp,"%lf %lf\n",v[i],u[i]);
	}
	printf("j=%d\n",j);
	fclose(fp);
 }
 void count(double v[],int M,int u[])
 {
 	for(int i=0;i<=B*100;i++)
 	{
 		u[i]=0;
 		for(int k=1;k<=M;k++)
 		{
 			if((v[k]>(2900+0.01*i))&&(v[k]<(2900+0.01*(i+1))))
 			{
 				u[i]=u[i]+1;
			}
		}
	 }
 }
 void output_2(int u[])
 {
 	FILE *fp;
	fp=fopen("q-2.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=0;i<=B*100;i++)
	{
		fprintf(fp,"%lf %d\n",(double)2900+0.01*i,u[i]);
	}
	fclose(fp);
 }
