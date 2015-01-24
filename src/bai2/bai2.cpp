#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define RANGE 20
using namespace std;


int N, **C;
int X[100]={0}, BestWay[100]={0}; //X de thu cac kha nang, BestWay de ghi nhan nghiem
int T[100]={0}, Free[100]={0}, MinCost=100000;

void capphat(int n);
void nhapfile(const char* filename="bai2.in");
void xuatmh();
void taodulieu(int n, const char* filename="bai2.in");
void init();

void findway(int i)
{
  int j;
  for (j=1;j<N;j++)
    {
      if (Free[j]==0)
	{
	  X[i]=j;
	  T[i]=T[j-1]+C[X[i-1]][j];
	  if (T[i]<MinCost)
	    {
	      if (i<N-1) //Neu di chua het
		{
		  Free[j]=1;
		  findway(i+1);
		  Free[j]=0;
		}
	      else //Neu da di het
		{
		  if (T[N-1]+C[X[N-1]][0] < MinCost) //Neu ton it chi phi hon
		    {
		      int k;
		      for (k=0;k<N;k++)
			BestWay[k]=X[k];
		      MinCost=T[N-1]+C[X[N-1]][0];
		    }
		}
	    }
	}
    }
}


int main()
{
  int i;
  init();
  taodulieu(5);
  nhapfile();
  findway(1);
  for (i=0;i<N;i++)
    cout<<BestWay[i]<<'\t';
  cout<<endl;
  cout<<MinCost;
  cout<<endl;
}

void init()
{
  Free[0]=1; //Da di qua thanh pho 0
  X[0]=0; //Xuat phat tu thanh pho 0
  T[0]=0;
}


void capphat(int n)
{
  N=n;
  C=new int*[n];
  int i;
  for (i=0;i<n;i++)
    C[i]=new int[n];
}

void nhapfile(const char* filename)
{
  ifstream inp(filename);
  int n,i,j;
  inp>>n;
  capphat(n);
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      inp>>C[i][j];
}



void xuatmh()
{
  int i,j;
  cout<<"\nXuat:"<<endl;
  for (i=0;i<N;i++)
    {
      for (j=0;j<N;j++)
	{
	  cout<<C[i][j]<<'\t';
	}
      cout<<endl;
    }
  cout<<endl;
}

void taodulieu(int n,const char* filename)
{
  int i,j,a,tmp[100][100];
  ofstream outfile(filename);
  outfile<<n<<endl;
  srand(time(NULL));
  for (i=0;i<n*n;i++)
    {
      for (j=i;j<n;j++)
	{
	  if (i!=j)
	    tmp[i][j]=tmp[j][i]=1+rand()%RANGE;
	  else
	    tmp[i][j]=0;
	}
    }
  for (i=0;i<n*n;i++)
    {
      for (j=0;j<n;j++)
	outfile<<tmp[i][j]<<'\t';
      outfile<<endl;
    }
  outfile<<endl;
  outfile.close();
}
