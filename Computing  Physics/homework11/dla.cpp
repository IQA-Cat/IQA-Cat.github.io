#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
int w ; //Width
int h;//Height
int E[1000][1000];//Function "Exist"
int y_r;//Range of y
int x_r;//Range of x
int y_c;//Center of y
int x_c;//Center od x
int x_b;//Bottom of x
int y_b;//Bottom of y
int x_u;//Top of x
int y_u;//Top of y
static inline bool Near(int x, int y);
void Range(int R_x, int R_y);
void Generator(int *p_x, int *p_y);
void Initial(void);
static inline void walk(int *p_x, int *p_y);
int main(void)
{
	int x, y;//position  
	int N;//Number of points generated in the first circle
	cout << "Input how many points you want to generate in first circle(recommended as 3500):" << endl;
	cin >> N;
	cout << "Input the width and height where you want to generate in(recommended as both 1000):" << endl;
	cin >> w >> h;
	int M;
	cout << "Input how many stages you want to generate in(recommended as 4):" << endl;
	cin >> M;//Number of stage
	const double d=1.56457;//Dimension of fractal, as a modified constant 
	double n=0;//Number of all generated points
	for (int i=1;i<=M;i++)
	{
		n += pow((double)i, d);
	}
	cout << "You actually generate " << (int)n*N << " points" << endl;
	system("pause");
	srand(time(0));//rand number
	Initial();//give the first point
	ofstream fout("test.dat");//open file
	for (int i = 1; i <= M; i++)
	{
		Range(i*w / (M + 1), i* h / (M + 1));//set radius of every circle
		int k = 0;//A auxilary number which using below for out-put percent of the program  
		for (int j = 0; j < N*(int)pow((double)i,d); j++)
		{
			Generator(&x, &y);//generates points
			fout << x - w / 2 << " " << y - h / 2 << endl;//out put in file,
			if ((100 * j /( N*(int)pow((double)i, d)) - (100 * j /( N*(int)pow((double)i, d))) % 10) / 10 - (100 * (j - 1) / (N*(int)pow((double)i, d) )- (100 * (j - 1) /( N*(int)pow((double)i, d))) % 10) / 10 == 1)//a whatever things
			{
				k++;
				cout << "The stage " << i << " completed as " << k*10 << "%"<<endl;
			}
		}
		cout << " The stage " << i << " completed" << endl;
		system("pause");
	}
	cout<< "finished" << endl;
	fout << flush;
	fout.close();//close file
	return 0;
}
void Range(int R_x, int R_y)//set range of every stage
{
	x_r = R_x / 2;
	y_r = R_y / 2;
	x_b = x_c - R_x / 2;
	y_b = y_c - R_y / 2;
	x_u = x_c + R_x / 2;
	y_u = y_c + R_y / 2;
}
void Generator(int *p_x, int *p_y)
{
	do
	{
		*p_x = (int)x_r*cos(rand()) + x_c;
		*p_y = (int)y_r*cos(rand()) + y_c;
	} while (E[*p_y][*p_x] == 1);//which generates in a circle whose center is first point and radius  as user setted.
	while (Near(*p_x, *p_y) == false)
	{
		walk(p_x, p_y);
	}
	E[*p_y][*p_x] = 1;//fix the point near the others 
	return;
}
void Initial(void)//set the center as the first point
{
	int x, y;
	x_c = w / 2;
	y_c = h / 2;

	for (y = 0; y < h; y++)
	{
		for (x = 0; x < w; x++)
		{
			E[y][x] = 0;
		}
	}
	E[y_c][x_c] = 1;
}
static inline void walk(int *p_x, int *p_y)
{
	int w;
	w = rand() % 4;//a lazy job,but...... IT WORKS
	switch (w)
	{
	case 0: // Right  
		(*p_x)++;
		break;
	case 1: // Left  
		(*p_x)--;
		break;
	case 2: // Down  
		(*p_y)++;
		break;
	case 3: // Up  
		(*p_y)--;
		break;
	default:
		break;
	}
	if (*p_x > x_u || *p_y > y_u || *p_x < x_b || *p_y < y_b)//Reset the point which attach the boundary
	{
		*p_x = (int)x_r*cos(rand()) + x_c;
		*p_y = (int)y_r*cos(rand()) + y_c;
	}
	return;
}
static inline bool Near(int x, int y)//Tell the program if there is point in the neighborhood
{
	int x_t, y_t;//a temporary quantity
	x_t = x + 1;// Right 
	if (x_t > x_u)
	{
		x_t = x_b + x_t - x_u;
	}//actually we don't need this...but just for fun we identify the boundary! Both the below 
	if (E[y][x_t] == 1)
	{
		return true;
	}
	y_t = y + 1; // Up 
	if (y_t > y_u)
	{
		y_t = y_b + y_t - y_u;
	}
	if (E[y_t][x] == 1)
	{
		return true;
	}
	y_t = y - 1;// Down 
	if (y_t < y_b)
	{
		y_t = y_u - (y_b - y_t);
	}
	if (E[y_t][x] == 1)
	{
		return true;
	}
	x_t = x - 1;// Left
	if (x_t < x_b)
	{
		x_t = x_u - (x_b - x_t);
	}
	if (E[y][x_t] == 1)
	{
		return true;
	}
	return false;
}
