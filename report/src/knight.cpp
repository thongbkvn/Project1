#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define N 4 // Kich thuoc ban co

/*
  CLASS BAN CO
  Thuoc tinh:
  +) A[N][N]: Trang thai ban co ve nhung vi tri quan ma da toi
  +) firstRow, firstCol: Vi tri xuat phat cua quan ma
  Phuong thuc:
  +) chessBoard(m,n): Khoi tao ban co, m,n la vi tri xuat phat cua quan ma
  +) printBoard(): Hien thi ban co
  +) Partol(m,n): Di tuan tu vi tri m*n
*/
class chessboard
{
private:
	int A[N][N];
	int firstRow, firstCol;
public:
	chessboard(int m=0,int n=0)
		{
			int i, j;
			for (i = 0; i<N; i++)
				for (j = 0; j < N; j++)
					A[i][j] = 0;
			firstRow = m;
			firstCol = n;
			A[m][n] = 1;
		}

	void printBoard() //Hien thi ban co
		{
			int i, j;
			static int n = 1; // Bien phu, khong can de y
			cout<<"\nCach "<<n<<":\n"<<endl;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
					cout<<setw(3)<<A[i][j];
				cout<<endl;
			}
			n++;
			cout<<endl;
		}
	// Tim nuoc di, nuoc di dau tien da duoc di tai firstRow, firstCol
	void Patrol(int m, int n, int k=2) 
		{
			int i, j;
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++)
					// Neu co the di duoc toi o i,j va o do chua duoc di toi
					if (((fabs(i-m) + fabs(j-n)) == 3) && (i!=m && j!=n && A[i][j]==0))
					{
						// Thu di toi A[i][j], luu ket qua va dau hieu vao mang A
						A[i][j] = k;
						// Neu da la nuoc di cuoi
						if (k == N*N) 
						{
							printBoard(); // Hien thi ban co
							// Buoc dau tien thi khong bo danh dau
							//Neu khong thi bo danh dau
							if ((i != firstRow) && (j != firstCol)) 
								A[i][j]=0; 
						}
						else
						{
							Patrol(i, j, k+1); // Thu di nuoc tiep theo
							A[i][j] = 0; // Bo danh dau
						}
					}
		}
	      


};


int main()
{
	int m,n;
	cout<<"BAI TOAN MA DI TUAN\nKich thuoc: "<<N<<'x'<<N<<endl;
	cout<<"Nhap vi tri xuat phat: ";
	cin>>m>>n;
	chessboard a(m,n);
	a.Patrol(m,n);
	cout<<endl;
	return 0;
}
  
