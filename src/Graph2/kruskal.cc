#include <iostream>
#include <fstream>
#include <iomanip>


#define max 100
#define INT_MAX 1000
int V, nEdge, A[max][max], MST[max][max], parent[max];


//Cau truc 1 canh
struct Edge
{
    int u, v, weight;
};

//Khai bao mang cac canh
Edge edge[10*max];

void Sort();
int Find_Set(int);
void Union(int, int);

void Kruskal()
{
    //Sap xep cac canh theo chieu tang dan cua trong so
    Sort();

  
    //Duyet tat ca cac canh
    for (int i=0; i<nEdge; i++)
    {
	//u va v la 2 dau mut cua canh i

	//tim nut goc cua dinh u
	int u = Find_Set(edge[i].u);
	int v = Find_Set(edge[i].v);

	//Neu u giong v thi u va v co cung dinh goc
	//vi vay can kiem tra u va v khong cung goc
	if (u != v)
	{
	    int x = edge[i].u;
	    int y = edge[i].v;
	    //Luu lai cay bao trum
	    MST[x][y] = MST[y][x] = edge[i].weight;
	    //Ket noi dinh u va dinh v
	    Union(u,v);
	}
    }
}

//Ham sap xep canh theo trong so
void Sort()
{
    for (int i=0; i<nEdge; i++)
	for (int j=nEdge-1; j>i; j--)
	    if (edge[j-1].weight > edge[j].weight)
	    {
		Edge tmp = edge[j-1];
		edge[j-1] = edge[j];
		edge[j] = tmp;
	    }
}

//Ham tim nut cha 1 dinh
int Find_Set(int x)
{
    while (parent[x] > -1)
    {
	x = parent[x];
    }
    return x;
}

//Ham ket noi 2 nut lai voi nhau
void Union(int u, int v)
{
    if (parent[u] > parent[v])
    {
	parent[v] += parent[u];
	parent[u] = v;
    }
    else
    {
	parent[u] += parent[v];
	parent[v] = u;
    }
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
    

    for (int i=0; i<V; i++)
	parent[i] = -1;
    
    for (int i=0; i<V; i++)
	for (int j=0; j<i; j++)
	    if (A[i][j] < INT_MAX)
	    {
		edge[nEdge].u = j;
		edge[nEdge].v = i;
		edge[nEdge].weight = A[i][j];
		nEdge++;
	    }

    Kruskal();
        



    for (int i=0; i<V; i++)
    {
	for (int j=0; j<V; j++)
	    std::cout << std::setw(4) << MST[i][j];
	std::cout << std::endl;
    }
    
}
