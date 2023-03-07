#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
using namespace std;
int Input_dim();
double Input_step();
int Input_num();
int walk(int x); 
inline bool WALK(int n_t, int d);
bool Back(int d, int x[]);
int count(int M, int n_t, int d);
void write(ofstream &file, double n, int M, int j);
int main()
{
    int d=Input_dim();//Input function of dimension
    double n=Input_step();//Input funciton of steps of random walk
    int M=Input_num();//Input function of number of particles
	ofstream *file;
	file = new ofstream[50];
	string *filename;
	string sname, tname, str;
	filename = new string[50];
	char b[5];
	char c[10];
	for (int i = 1; i <= d; i++)//Set the name of the file
	{
		sprintf_s(b, "%d", i );
		str = b;
		sprintf_s(c, ".dat");
		tname = c;
		filename[i] = str + tname;
	}
	for (int j = 1; j <= d; j++)//main function
	{
		file[j].open(filename[j], ios::out);
		write(file[j], n, M, j);
	}
	cout << "Finished" << endl;//Sign of the programm finished
	system("pause");
}
int Input_dim()
{
	int d;
    do//To make sure dimension is postive
    {
        cout<<"Input dimension:";  
        cin>>d;
    }while(d<=0);
    return(d);
}
double Input_step()
{
	int N;
	double n;
    do
    {
        cout<<"Input max steps:";
        cin>>N;
        n=(log((double)N)/(20*log(2.0)));//To make "n" is average in "ln" axis
	} while (N < 10000);//To make sure "N" the number of steps is large enough
    return(n);
}
int Input_num()
{
    int M;
    do
    {
        cout<<"Input particle numbers(al least 10000):";
        cin>>M;
    }while(M<10000);//To make sure "M" the number of particle is large enough
    return(M);
}
int walk(int x)
{
	switch (rand() % 2)//Random in a dimension
        {
			case 0:
            x+=1;
            break;
			case 1:
            x+=-1;
            break;
			default:
            break;
        }
        return(x);//Only make difference in the input "x" and output back
}
static inline bool WALK(int n_t,int d)
{
    int *x;
    x=(int *)malloc(d*sizeof(int));//Set position number 
	for (int i = 1; i <= d; i++)//Initial position
	{
		x[i] = 0;
	}
    for(int i=1;i<=n_t;i++)//For a chosen step
    {
        for(int j=1;j<=d;j++)//For every dimension
        {
            x[j]=walk(x[j]);
        }
        if(Back(d,x)==true)//If found the back particle then break
        {
            return(true);
        }
    }
    return(false);
    free(x);
}
static inline bool Back(int d,int x[])//Judge if the paticle go back to zero point
{
    int t=0;//A temp-variable
    for(int i=1;i<=d;i++)
    {
        if(x[i]==0)
        t++;
    }
    if(t==d)
    return(true);
    else
    return(false);
}
int count(int M,int n_t,int d)//Count function
{
    int t=0;
    for(int i=1;i<=M;i++)
    {
        if(WALK(n_t,d)==true)
        t++;
    }
    return(t);
}
void write(ofstream &file, double n, int M,int j)//Output function
{
	for (int i = 1; i <= 20; i++)
	{
		if (pow(2.0, (double)i*n) > 100)
		{
			double p = (double)count(M, pow(2, i*n), j) / (double)M;
			cout << "n=" << count(M, pow(2, i*n), j) << endl;//Output Count number in screen
			cout << pow(2.0, (double)i*n) << " " << p << endl;
			file << pow(2.0, (double)i*n) << " " << p << endl;
		}
	}
	file.close();
}
