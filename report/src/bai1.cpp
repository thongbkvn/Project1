#include <iostream>
#include <fstream> //Su dung nhap xuat file
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#define RANGE 100
#define LENGTH 30



using namespace std;

class numberSequence
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
  void swap(int& m,int &n);
  //Cac ham xuat nhap file
  void input();
  void importFile(const char* filename="bai1.in");
  void outScreen();
  void exportFile(const char* filename="bai1.out");
 
  int bubleSort();
  void selectionSort();
  void insertionSort();
  void shellSort();
  //Quick Sort  
  void quickSort()
  {
    partition(0,len-1);
  }
  void partition(int L, int H);

  //Heap Sort
  void maxHeapify(int root, int endnode);
  void heapSort();
    
};

//Tao dau vao vao gom n so vao file co ten la filename
void makeData(int n,const char* filename="bai1.in");


int main(void)
{
  numberSequence list;

  makeData(LENGTH);
  list.importFile();
  list.bubleSort();
  list.outScreen();
  cout<<endl;
  return 0;
}


void numberSequence::maxHeapify(int root, int endnode)
{
  int c, key;
  key=arr[root];
    
  while ((root*2 +1) <= endnode) //Khi nao root chua phai la la
    {
      c=root*2+1;
      if (c<endnode-1 && arr[c]<arr[c+1])
	c++; //Neu con trai be hon con phai thi c=chi so con phai
      if (arr[c]<=key) //Neu 2 con be hon root thi cay da la maxheap
	break;
      arr[root]=arr[c]; //Doi cho cho con lon hon
      root=c; // Tiep tuc voi root tai vi tri moi
    }
  arr[root]=key; //root ban dau nam dung vi tri  
}

void numberSequence::heapSort()
{
  int r, i;
  for (r=(len/2-1); r>=0;r--) // Xay dung dong tren toan bo cay
    maxHeapify(r,len-1);
  // outScreen();
  for (i=len-1;i>0;i--)
    {
      swap(arr[0],arr[i]); //Doi cho nut lon nhat ve cuoi day
      // outScreen();
      maxHeapify(0,i-1); //Xay lai dong, ko kem nut vua hoan doi
    }
}


//Quick sort
void numberSequence::partition(int L, int H)
{
  int i,j,pivot;
  
  if (L>=H) //Neu chi co duoi 1 phan tu thi khong phai lam di
    return;
  i=L;j=H;
  srand(time(NULL));
  pivot=arr[L+rand()%(H-L+1)]; //Chon chot ngau nhien, tranh cac truong hop dac biet

  while (i<=j)
    {
      while (arr[i]<pivot) //Tim phan tu lon hon hoac bang pivot tu trai sang
	i++;
      while (arr[j]>pivot) //Tim phan tu lon hon hoac bang pivot tu phai sang
	j--;

      if (i<=j)
	{
	  if (i<j) //Neu tim thay va hai phan tu do khac nhau thi doi cho
	    swap(arr[i],arr[j]); 
	  i++; j--;
	}
    }
  partition(L,j); //Tiep tuc voi day con trai
  partition(i,H); //Tiep tuc voi day con phai
}


void numberSequence::insertionSort()
{
  int i,j,tmp;
  
  for (i=1;i<len;i++)
    {
      tmp=arr[i]; //Chen phan tu arr[i] vao day da co thu tu
      j=i-1;
      while (j>=0 && arr[j]>tmp) //Tim tu ben phai sang phan tu be hon arr[i]
	{
	  arr[j+1]=arr[j]; //Don cac phan tu ve ben phai tao 1 cho chua cho arr[i]
	  j=j-1;
	}
      arr[j+1]=tmp; //Chen phan tu vao dung vi tri, day arr[0]-->arr[i] la day tang dan
    }
}


void numberSequence::shellSort()
{
  int i,j,h=len/2,tmp;
  
  while (h>0) 
    {
      for (i=h;i<len;i++) //Sap xep chen voi cac day con
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
      h=h/2; //Tang so day con
    }
}

//Sap xep noi bot
int numberSequence::bubleSort()
{
  int i,j,s=0;
  for (i=1;i<len;i++)
    for (j=len-1;j>=i;j--)
      if (arr[j]<arr[j-1])
	{
	  swap(arr[j],arr[j-1]);
	  s++;
	}
  return s;
}


void numberSequence::swap(int& m,int &n) //Doi cho 2 phan tu
{
  m=m+n;
  n=m-n;
  m=m-n;
}


void numberSequence::selectionSort() 
{
  int i,j,min;
  for (i=0;i<len-1;i++)
    {
      min=i; //Dat arr[i] lam phan tu be nhat
      for (j=i+1;j<len;j++) //Tim phan tu be nhat trong day arr[i]-->arr[len-1]
	if (arr[j]<arr[min])
	  min=j;
      if (i!=min)
	swap(arr[i],arr[min]); //Doi cho phan tu be nhat ve vi tri, day arr[0]-->arr[i] la day tang dan
    }
}

//Ham nhap day so tu ban phim
void numberSequence::input()
{
  int i, n;
  cout<<"\nNhap so phan tu cua day: ";
  cin>>n;
  allocate(n);
  cout<<"\nNhap "<<len<<" so nguyen tu ban phim:"<<endl;
  for (i=0;i<len;i++)
    cin>>arr[i];
}
//Ham nhap day so tu file
void numberSequence::importFile(const char* filename)
{
  ifstream inp(filename);
  int n,i;
  inp>>n;
  allocate(n);
  for (i=0;i<n;i++)
    inp>>arr[i];
}
//Ham xuat day so ra man hinh
void numberSequence::outScreen()
{
  int i;
  cout<<endl;
  for (i=0;i<len;i++)
    {
      cout<<setw(8)<<arr[i];
      if (i%10==9)
	cout<<endl;
    }
  cout<<endl;
}

void numberSequence::exportFile(const char* filename)
{
  ofstream outp(filename);
  int i;
  outp<<len<<endl;
  for (i=0;i<len;i++)
    {
      outp<<setw(8)<<arr[i];
      if (i%10==9)
	outp<<endl;
    }
  outp<<endl;
  outp.close();
}
//Ham tao day gom n so ngau nhien vao filename
void makeData(int n, const char* filename)
{
  int i,a;
  ofstream outfile(filename);
  outfile<<n<<endl;
  srand(time(NULL));//Khoi tao chuoi so ngau nhien theo thoi gian
  for (i=0;i<n;i++)
    {
      a=rand()%RANGE;
      outfile<<setw(8)<<a;
      if (i%10 ==9)
	outfile<<endl;
    }
  outfile<<endl;
  outfile.close();
}


