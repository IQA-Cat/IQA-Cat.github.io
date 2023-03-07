#include<iostream>
#include<math.h>
#include<fstream>
#include<time.h>
#include<string>
using namespace std;
int e[1000][1000];
int e_t[1000][1000];
int n_1, n_2, n_3, n_4;
int t_1, t_2, t_3, t_4;
int y_t, y_b, x_t, x_b;
void initial(int N, double r);
void involution(int N, double r);
void integer(int e);
void Range(int r, double theta, double delta);
void WriteFile(ofstream &file, int N);
void main()
{
	ofstream *file;
	file = new ofstream[50];
	string *filename;
	string sname, tname, str;
	cout << "Input the LENTH of the space:" << endl;
	int N;
	cin >> N;
	cout << "Input THETA which is the degree of the broken bound:" <<endl;
	double theta, delta;
	cin >>theta;
	cout << "Input DELTA which is the wide of the broken bound:" << endl;
	cin >> delta;
	cout << "Input the RADIUS:" << endl;
	double r;
	cin >> r;
	r += 0.5;
	initial(N,r);
	cout << "Input times:" << endl;
	int n;
	cin >> n;
	Range(r,  theta,  delta);
	int l = (n-n%100)/100;
	filename = new string[50];
	char b[20];
	char c[10];
	for (int i = 0; i <= l; i++)
	{
		sprintf_s(b, "%d", (i+1)*100);
		str = b;
		sprintf_s(c, ".dat" );
		tname = c;
		filename[i] = str + tname;
	}
	int k=0;
	for (int i = 1; i <= n; i++)
	{
		involution(N, r);
		if (((i+1 - ((i+1) % 100)) / 100- (i - (i % 100)) / 100) != 0||i==1)
		{
			file[k].open(filename[k], ios::out);
			WriteFile(file[k],N);
			k++;
		}
	}
}
void Range(int r, double theta,double delta)
{
	y_t = r*sin(theta + delta / 2);
	x_t = r*cos(theta + delta / 2);
	y_b = r*sin(theta - delta / 2);
	x_b = r*cos(theta - delta / 2);
}
void WriteFile(ofstream &file,int N)
{
	int i, j;
	for (i = 0; i <=N ; i++)
	{
		for (j = 0; j <=N ; j++)
		{
			if (e[i][j] != 0)
			{
				integer(e[i][j]);
				int temp = n_1 + n_2 + n_3 + n_4;
				file << i<< " "<<j<</*" "<<temp<<*/endl;
			}
		}
	}
	file.close();
	cout << "Finished" << endl;
}
void initial(int N,double r)

{
	for (int i = 0; i <= N; i++)
	{
		int j;
		for (j = 0; j <= N; j++)
		{
			if ((i-N/2)*(i-N/2) + (j-N/2)*(j-N/2) <= (r-1)*(r-1))
			{
				int w;
				w = rand() % 4;
				switch (w)
				{
				case 0:  
					e[i][j] = 1;
					break;
				case 1:  
					e[i][j] = 10;
					break;
				case 2:   
					e[i][j] = 100;
					break;
				case 3:  
					e[i][j] = 1000;
					break;
				default:
					e[i][j] = 0;
					break;
				}
			}
			else
			{
				e[i][j] = 0;
			}
			e_t[i][j] = 0;
		}
	}
}
void involution(int N,double r)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			int x = i - N / 2; 
			int y = j - N / 2;
			if ((y<=y_t)&&y>=y_b&&x>=x_b-2&&x<=x_t+2)
			{
				integer(e[i][j]);
				e_t[i][j + 1] += (t_4) * 1;
				e_t[i][j - 1] += (t_2) * 100;
				e_t[i + 1][j] += (t_3) * 10;
				e_t[i - 1][j] += (t_1) * 1000;
				e_t[i][j] += 0;
			}
			else
			{
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y > r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) <=r*r)//Right
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += 0 * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y > r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) <=r*r)//Left
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += 0 * 1000;
					e_t[i][j] += (t_1) * 10;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) > r*r && x*x + (y + 1)*(y + 1) <=r*r)//Down
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += 0 * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_2);
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) > r*r)//Up
				{
					integer(e[i][j]);
					e_t[i][j + 1] += 0 * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_4) * 100;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y > r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) > r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_4) * 100 + (t_1) * 10;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y > r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) > r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_4) * 100;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y > r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) > r*r && x*x + (y + 1)*(y + 1) <=r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_2) * 1;
					goto add;
				}
				if (x*x + y*y <=r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y > r*r && x*x + (y - 1)*(y - 1) > r*r && x*x + (y + 1)*(y + 1) <=r*r )
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_1) * 10 + (t_2) * 1;
					goto add;
				}

				//aaaaaa
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y >r*r && x*x + (y - 1)*(y - 1) >r*r && x*x + (y + 1)*(y + 1) >r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += 0 * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y >r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) >r*r && x*x + (y + 1)*(y + 1) >r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += 0 * 1000;
					e_t[i][j] += (t_1) * 10;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y >r*r && (x - 1)*(x - 1) + y*y >r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) >r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += 0 * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_2);
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y >r*r && (x - 1)*(x - 1) + y*y >r*r && x*x + (y - 1)*(y - 1) >r*r && x*x + (y + 1)*(y + 1) <=r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += 0 * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_4) * 100;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y >r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) >r*r && x*x + (y + 1)*(y + 1) <=r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_4) * 100 + (t_1) * 10;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y >r*r && x*x + (y - 1)*(y - 1) >r*r && x*x + (y + 1)*(y + 1) <=r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_4) * 100;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y <=r*r && (x - 1)*(x - 1) + y*y >r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) >r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_2) * 1;
					goto add;
				}
				if (x*x + y*y >r*r && (x + 1)*(x + 1) + y*y >r*r && (x - 1)*(x - 1) + y*y <=r*r && x*x + (y - 1)*(y - 1) <=r*r && x*x + (y + 1)*(y + 1) >r*r)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_1) * 10 + (t_2) * 1;
					goto add;
				}


				if (1 + i > N && i - 1 > 0 && j - 1 > 0 && j + 1 < N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += 0 * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000;
					goto add;
				}
				if (1 + i < N && i - 1 < 0 && j - 1 > 0 && j + 1 < N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += 0 * 1000;
					e_t[i][j] += (t_1) * 10;
					goto add;
				}
				if (1 + i < N && i - 1 > 0 && j - 1 < 0 && j + 1 < N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += t_4;
					e_t[i][j - 1] += 0 * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_2);
					goto add;
				}
				if (1 + i < N && i - 1 > 0 && j - 1 > 0 && j + 1 > N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += 0 * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_4) * 100;
					goto add;
				}
				if (1 + i  < N && i - 1 < 0 && j - 1 > 0 && j + 1 > N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_4) * 100 + (t_1) * 10;
					goto add;
				}
				if (1 + i > N && i - 1 > 0 && j - 1 > 0 && j + 1 > N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (0) * 1;
					e_t[i][j - 1] += (t_2) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_4) * 100;
					goto add;
				}
				if (1 + i > N && i - 1 > 0 && j - 1 < 0 && j + 1 < N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (0) * 10;
					e_t[i - 1][j] += (t_1) * 1000;
					e_t[i][j] += (t_3) * 1000 + (t_2) * 1;
					goto add;
				}
				if (1 + i < N && i - 1 < 0 && j - 1 < 0 && j + 1 < N)
				{
					integer(e[i][j]);
					e_t[i][j + 1] += (t_4) * 1;
					e_t[i][j - 1] += (0) * 100;
					e_t[i + 1][j] += (t_3) * 10;
					e_t[i - 1][j] += (0) * 1000;
					e_t[i][j] += (t_1) * 10 + (t_2) * 1;
					goto add;
				}
				integer(e[i][j]);
				e_t[i][j + 1] += (t_4) * 1;
				e_t[i][j - 1] += (t_2) * 100;
				e_t[i + 1][j] += (t_3) * 10;
				e_t[i - 1][j] += (t_1) * 1000;
				e_t[i][j] += 0;
			}
		add:;
		}
	}
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			e[i][j] = e_t[i][j];
			e_t[i][j] = 0;
		}
	}
}
void integer(int e)
{
	n_1 = (e - e % 1000) / 1000;
	n_2 = (e - e % 100) / 100 % 10;
	n_3 = (e - e % 10) / 10 % 10;
	n_4 = e % 10;
	t_1 = (int)fmin((double)n_2, (double)n_4) + n_1 - (int)fmin((double)n_3, (double)n_1);
	t_2 = (int)fmin((double)n_1, (double)n_3) + n_2 - (int)fmin((double)n_2, (double)n_4);
	t_3 = (int)fmin((double)n_2, (double)n_4) + n_3 - (int)fmin((double)n_3, (double)n_1);
	t_4 = (int)fmin((double)n_3, (double)n_1) + n_4 - (int)fmin((double)n_2, (double)n_4);
 }