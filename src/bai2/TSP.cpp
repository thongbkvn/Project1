#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#define CITY 5
#define RANGE 20
using namespace std;


int N, **C;
int X[100], BestWay[100]; //X thu cac kha nang, BestWay ghi nhan nghiem
int T[100], Free[100], MinCost=100000; //T luu so tien, Free danh dau nhung diem da qua

void allocate(int n);
void importFile(const char* filename="bai2.in");
void outScreen();
void makeData(int n, const char* filename="bai2.in");
void init();

void findWay(int i)
{
  int j;
  for (j=1;j<N;j++)//Cac gia tri co the nhan
    {
      if (Free[j]==0) //Neu chua di qua
	{
	  X[i]=j; //Thu di qua j
	  T[i]=T[i-1]+C[X[i-1]][j];
	  if (T[i]<MinCost) //Neu co kha nang di qua vs chi phi thap hon
	    {
	      if (i<N-1) //Neu di chua het
		{
		  Free[j]=1; //Danh dau da di qua
		  findWay(i+1); //Di tiep
		  Free[j]=0; //Quay lai thanh pho, bo danh dau
		}
	      else //Neu da di het
		{
		  if (T[N-1]+C[X[N-1]][0] < MinCost) //Neu ton it chi phi hon
		    {
		      int k;
		      for (k=1;k<N;k++) //Cap nhat cau hinh tot nhat		 
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
  makeData(CITY);    //Tao du lieu dau vao
  importFile();
  
  findWay(1);
  
  for (i=0;i<N;i++)
    cout<<BestWay[i]<<"-->";
  cout<<0<<endl;
  cout<<MinCost;
  
  cout<<endl;
}

void init()
{
  Free[0]=1; //Da di qua thanh pho 0
  X[0]=0; //Xuat phat tu thanh pho 0
  T[0]=0;
}


void allocate(int n)
{
  N=n;
  C=new int*[n];
  int i;
  for (i=0;i<n;i++)
    C[i]=new int[n];
}

void importFile(const char* filename)
{
  ifstream inp(filename);
  int n,i,j;
  inp>>n;
  allocate(n);
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      inp>>C[i][j];
}



void outScreen()
{
  int i,j;
  cout<<"\nXuat:"<<endl;
  for (i=0;i<N;i++)
    {
      for (j=0;j<N;j++)
	{
	  cout<<setw(4)<<C[i][j];
	}
      cout<<endl;
    }
  cout<<endl;
}

void makeData(int n,const char* filename)
{
  int i,j,a,tmp[100][100];
  ofstream outfile(filename);
  outfile<<n<<endl;
  srand(time(NULL));
  for (i=0;i<n;i++)
    {
      for (j=i;j<n;j++)
	{
	  if (i!=j)
	    tmp[i][j]=tmp[j][i]=1+rand()%RANGE;
	  else
	    tmp[i][j]=0;
	}
    }
  for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++)
	outfile<<setw(4)<<tmp[i][j];
      outfile<<endl;
    }
  outfile<<endl;
  outfile.close();
}
