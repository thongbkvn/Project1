#include <iostream>
#include <fstream> //Su dung nhap xuat file
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#define RANGE 99999999
#define LENGTH 100000



using namespace std;

class noSeq
{
private:
  int len;
  int *arr;
public:
  //Ham tao dung cap phat bo nho
  void allocate(int n)
  {
    arr=new int[n];
    len=n;
  }

  //hoan vi arr[m] va arr[n]
  void swap(int m,int n);
  //Cac ham xuat nhap file
  void input();
  void importFile(const char* filename="bai1.in");
  void outScreen();
  void exportFile(const char* filename="bai1.out");
 
  int bubleSort();
  void selectionSort();
  void insertionSort();
  void shellSort();
  
  void quickSort()
  {
    partition(0,len-1);
  }
  void partition(int L, int H)
  {
    int i,j,pivot;
    if (L>=H)
      return;
    i=L;j=H;
    pivot=arr[L];

    do
      {
	while (arr[i]<pivot)
	  i++;
	while (arr[j]>pivot)
	  j--;
	if (i<=j)
	  {
	    if (i<j)
	      swap(i,j);
	    i++; j--;
	  }
      }
    while (i<j);
    partition(L,j);
    partition(i,H);
  }
};



//Tao left vao
void makeData(int n,const char* filename="bai1.in");


int main(void)
{
  noSeq list;

  // makeData(LENGTH);
  list.importFile();
  list.quickSort();
  list.exportFile();


  cout<<endl;
  return 0;
}


void noSeq::shellSort()
{
  int i,j,h=len/2,tmp;
  while (h>0)
    {
      for (i=h;i<len;i++)
	{
	  tmp=arr[i];
	  j=i-h;
	  while (j>=0 && arr[j]>tmp)
	    {
	      arr[j+h]=arr[j];
	      j=j-h;
	    }
	  arr[j+h]=tmp;
	}
      h=h/2;
    }
}

void noSeq::insertionSort()
{
  int i,j,tmp;
  for (i=1;i<len;i++)
    {
      tmp=arr[i];
      j=i-1;
      while (j>=0 && arr[j]>tmp)
	{
	  arr[j+1]=arr[j];
	  j=j-1;
	}
      arr[j+1]=tmp;
    }
}

void noSeq::swap(int m,int n)
{
  arr[m]=arr[m]+arr[n];
  arr[n]=arr[m]-arr[n];
  arr[m]=arr[m]-arr[n];
}


void noSeq::selectionSort()
{
  int i,j,min;
  for (i=0;i<len-1;i++)
    {
      min=i;
      for (j=i+1;j<len;j++)
	if (arr[j]<arr[min])
	  min=j;
      if (i!=min)
	swap(i,min);
    }
}
void noSeq::input()
{
  int i, n;
  cout<<"\nNhap so phan tu cua day: ";
  cin>>n;
  allocate(n);
  cout<<"\nNhap "<<len<<" so nguyen tu ban phim:"<<endl;
  for (i=0;i<len;i++)
    cin>>arr[i];
}

void noSeq::importFile(const char* filename)
{
  ifstream inp(filename);
  int n,i;
  inp>>n;
  allocate(n);
  for (i=0;i<n;i++)
    inp>>arr[i];
}

void noSeq::outScreen()
{
  int i;
  cout<<endl;
  for (i=0;i<len;i++)
    {
      cout<<setw(8)<<arr[i]<<' ';
      if (i%10==9)
	cout<<endl;
    }
  cout<<endl;
}

void noSeq::exportFile(const char* filename)
{
  ofstream outp(filename);
  int i;
  outp<<len<<endl;
  for (i=0;i<len;i++)
    {
      outp<<setw(8)<<arr[i]<<' ';
      if (i%10==9)
	outp<<endl;
    }
  outp<<endl;
  outp.close();
}

void makeData(int n, const char* filename)
{
  int i,a;
  ofstream outfile(filename);
  outfile<<n<<endl;
  srand(time(NULL));
  for (i=0;i<n;i++)
    {
      a=rand()%RANGE;
      outfile<<setw(8)<<a<<' ';
      if (i%10 ==9)
	outfile<<endl;
    }
  outfile<<endl;
  outfile.close();
}

//Sap xep noi bot
int noSeq::bubleSort()
{
  int i,j,s=0;
  for (i=0;i<len;i++)
    for (j=i+1;j<len;j++)
      if (arr[i]>arr[j])
	{
	  swap(i,j);
	  s++;
	}
  return s;
}


