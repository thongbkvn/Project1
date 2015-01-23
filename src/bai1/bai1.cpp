/*
  Doi tuong: Day so
  Thuoc tinh: 
              -Chieu dai.
              -Luu tru: Cap phat dong
  Phuong thuc:
              -Nhap day so
	          +Tu ban phim
		  +Tu file
	      -Xuat day so
	          +Tu ban phim
		  +Tu file
	      -Sap xep buble, heap, quick
*/


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class dayso
{
private:
  int len;
  int *p;
public:
  void capphat(int n)
  {
    p=new int[n];
    len=n;
  }
  int bublesort()
  {
    int i,j,s=0;
    for (i=0;i<len;i++)
      for (j=i+1;j<len;j++)
	{
	  if (p[i]>p[j])
	    {
	      p[i]=p[i]+p[j];
	      p[j]=p[i]-p[j];
	      p[i]=p[i]-p[j];
	      s++;
	    }
	}
    return s;
  }
  void nhapbp()
  {
    int i, n;
    cout<<"\nNhap so phan tu cua day: ";
    cin>>n;
    capphat(n);
    cout<<"\nNhap "<<len<<" so nguyen tu ban phim:"<<endl;
    for (i=0;i<len;i++)
      cin>>p[i];
  }
  void nhapfile(const char* filename="bai1.in")
  {
    ifstream inp(filename);
    int n,i;
    inp>>n;
    capphat(n);
    for (i=0;i<n;i++)
      inp>>p[i];
  }
  void xuatmh()
  {
    int i;
    cout<<"\nXuat day so:"<<endl;
    for (i=0;i<len;i++)
      {
	  cout<<p[i]<<'\t';
	  if (i%10==0)
	    cout<<endl;
      }
    cout<<endl;
  }
  void xuatfile(const char* filename="bai1.out")
  {
    ofstream outp(filename);
    int i;
    outp<<len<<endl;
    for (i=0;i<len;i++)
      {
	outp<<p[i]<<'\t';
	if (i%10==9)
	  outp<<endl;
      }
    outp<<endl;
    outp.close();
  }
};

void taodt(int n,const char* filename="bai1.in")
{
  int i;
  ofstream outfile(filename);
  outfile<<n<<endl;
  for (i=0;i<n;i++)
    {
	  outfile<<(rand()%20000-10000)<<'\t';
	  if (i%10 ==9)
	    outfile<<endl;
    }
  outfile<<endl;
  outfile.close();
}
int main(void)
{
  dayso list;
  int a;
  taodt(50000);
  cout<<"\nNhap du lieu";
  list.nhapfile();
  cout<<"\nSap xep..."<<endl;
  a=list.bublesort();
  cout<<"\nSap xep hoan thanh"<<endl;
  list.xuatfile();
  cout<<"\nSo lan trao doi: "<<a<<endl;
  return 0;
}
