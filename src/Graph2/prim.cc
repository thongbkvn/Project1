#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX 100
#define INT_MAX 1000

int V, //So dinh
    A[MAX][MAX],//Ma tran trong so
    MST[MAX][MAX]; //Do thi chua cay bao trum nho nhat

//Khoi tao cac bien can thiet cho thuat toan Prim
int parent[MAX], key[MAX];
bool Free[MAX];

int extractMin();
void Prim(int start)
{
    //Khoi tao cac bien
    //parent: nut cha cua nut hien taij
    //free: nut do da duoc tham hay chua
    //key: gia tri
    for (int i=0; i<V; i++)
    {
	parent[i] = -1;
	Free[i] = true;
	key[i] = INT_MAX;
    }

    //Bat dau qua trinh tim kiem
    key[start] = 0;

    for (int i=0; i<V-1; i++)
    {
	//Tim dinh tiep theo tu tat ca cac dinh da tim duoc
	//sao cho dinh moi tim duoc la canh nho nhat

	int u=extractMin();
	//Thong bao da tim duoc
	Free[u] = false;
	//Duyet het tat ca cac nut
	for (int v=0; v<V; v++)
	    //Neu nut do chua duoc tim thay
	    if (Free[v] && A[u][v] != 0 && A[u][v] < key[v])
	    {
		key[v] = A[u][v];
		parent[v] = u;
	    }
    }

    //MST la cay vua tim duoc
    //dua vao parent de truy vet va tim ra cay bao trum nho nhat

    for (int i=0; i<V; i++)
	MST[parent[i]][i] = MST[i][parent[i]] = A[parent[i]][i];
}

int extractMin()
{
    int min = INT_MAX, u;
    for (int i=0; i<V; i++)
	if (Free[i] && key[i] < min)
	{
	    min = key[i];
	    u = i;
	}
    return u;
}

int main()
{
    //Nhap du lieu cho ma tran
    std::ifstream in("mst_matrix.txt");
    in >> V;
    for (int i=0; i<V; i++)
	for (int j=0; j<V; j++)
	    in >> A[i][j];
    in.close();
    
    Prim(3);

    for (int i=0; i<V; i++)
    {
	for (int j=0; j<V; j++)
	    std::cout << std::setw(4) << MST[i][j];
	std::cout << std::endl;
    }
    return 0;
    
}
