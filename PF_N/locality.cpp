#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
int r,R;
int s,S;
double dim(int x,int N);
double db(int i1,int j1, int i2,int j2,int N,int y);
int max(int i1,int k1,int n);
int min(int i1, int k1);

int main(){
    int N;
    cout <<"Input the number n"<< endl;
    cin >>N;
    int i,j,k,l;
    cout<< "Input the index:"<<endl;
    cin >>i>>j>>k>>l;
    cout<< "you wanna to calculate the double braiding of M("<<i<<j<<","<<k<<l<<") with the condensable algebra."<<endl;
    system("pause");    
    int p=(int) N/2;
    for (int t = 0; t < p+1; t++)
    {
        R=min(i,2*t);
        r=max(i,2*t,N);
        S=min(k,2*t);
        s=max(k,2*t,N);
        // cout <<"s="<<s<<endl;
        // cout <<"S="<<S<< endl;
        cout<<"The double braiding of M("<< i << j <<","<< k << l <<") with M("<<2*t<<0<<","<<2*t<<0<<")is:";
        for (int a = s; a < S+1; a++)
        {
            // cout<<"a=:"<<a<<endl;
            for (int b=r; b < R+1; b++)
            {
                // cout<<"b=:"<<b<<endl;
                // cout <<"test:db1 is:" <<fixed <<db(i,j,2*t,0,N,b)<<endl;
                // cout <<"test:db2 is:" <<fixed <<db(k,l,2*t,0,N,a)<<endl;
                cout << fixed <<db(i,j,2*t,0,N,b)+db(k,l,2*t,0,N,a)<<endl;
            }
            
            
        }
    }
    system("pause");
}


double dim(int x,int N){
    double h;
    h=(double) x*(x+2)/(4*(N+2));
    return h;
    
}

double db(int i1,int j1, int i2,int j2,int N,int y){
    double x=dim(i1+i2-2*y,N)-dim(i1,N)-dim(i2,N)+j1*j2/(2*N);
    return x;
}

int max(int i1,int k1,int n){
    int t1;
    if (i1+k1-n>0)
    {
        t1=i1+k1-n;    /* code */
    }
    else 
    t1=0;
    return t1;
}

int min(int i1, int k1){
    int t2;
    if (i1>k1)
    {
        t2=k1;    /* code */
    }
    else 
    t2=i1;
    return t2;
}