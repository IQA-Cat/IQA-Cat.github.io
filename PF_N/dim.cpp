#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;


int main(){
    int n;
    cout << "Input the number n"<< endl;
    cin >> n;
	int P=floor(n/2);
	int i,j,k,l;
    cout << "Input the first index"<<endl;
    cin >>i>>j>>k>>l;
    cout << "Input the second index"<<endl;
	int i2,j2,k2,l2;
    cin >>i2>>j2>>k2>>l2;
    do 
    {
        cout<<"The answer is 0"<< endl;
    }
    while (j!=j2 or l!=l2)
    system("pause");
}