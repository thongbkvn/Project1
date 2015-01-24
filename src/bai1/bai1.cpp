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
#include <fstream> //Su dung nhap xuat file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 20
#define INF 4294967295
using namespace std;

class dayso
{
private:
  int len;
  int *p;
public:
  int bublesort();

  void merge(int dau, int giua, int duoi);
  void mergesort(int dau, int duoi)
  {
    int giua;
    if (dau<duoi)
      {
	giua=(dau+duoi)/2;
	mergesort(dau,giua);
	mergesort(giua+1,duoi);
	merge(dau,giua,duoi);
      }
  }
  
  //cap phat bo nho
  void capphat(int n)
  {
    p=new int[n];
    len=n;
  }

  //hoan vi p[m] va p[n]
  void hoanvi(int m,int n)
  {
    p[m]=p[m]+p[n];
    p[n]=p[m]-p[n];
    p[m]=p[m]-p[n];
  }

  //Cac ham nhap file
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

  //Cac ham xuat file
  void xuatmh()
  {
    int i;
    cout<<"\nXuat day so:"<<endl;
    for (i=0;i<len;i++)
      {
	cout<<p[i]<<'\t';
	if (i%10==9)
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

//Sap xep noi bot
int dayso::bublesort()
{
  int i,j,s=0;
  for (i=0;i<len;i++)
    for (j=i+1;j<len;j++)
      if (p[i]>p[j])
	{
	  hoanvi(i,j);
	  s++;
	}
  return s;
}

/* Sap xep tron
  
 */


void dayso::merge(int dau,int giua,int duoi)
{

  int i,m,k,l,temp[100];

  l=dau;
  i=dau;
  m=giua+1;

  while((l<=giua)&&(m<=duoi)){

    if(p[l]<=p[m]){
      temp[i]=p[l];
      l++;
    }
    else{
      temp[i]=p[m];
      m++;
    }
    i++;
  }

  if(l>giua){
    for(k=m;k<=duoi;k++){
      temp[i]=p[k];
      i++;
    }
  }
  else{
    for(k=l;k<=giua;k++){
      temp[i]=p[k];
      i++;
    }
  }
   
  for(k=dau;k<=duoi;k++){
    p[k]=temp[k];
  }
}


//Tao dau vao
void taodulieu(int n,const char* filename="bai1.in")
{
  int i,a;
  ofstream outfile(filename);
  outfile<<n<<endl;
  srand(time(NULL));
  for (i=0;i<n;i++)
    {
      a=rand()%RANGE;
      outfile<<a<<'\t';
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
  taodulieu(30);
  cout<<"\nNhap du lieu";
  list.nhapfile();
  list.xuatmh();
  list.mergesort(0,30);
  list.xuatmh();


  cout<<endl;
  return 0;
}
