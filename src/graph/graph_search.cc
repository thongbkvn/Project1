#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <queue>
#include <list>
#include "graph.h"
#include "graph_search.h"
using namespace std;

//Ham Tao
GraphSearch::GraphSearch(const char* filename)
{
    bool ward = true; //linh canh
	      		
    ifstream in(filename);
    in >> v;

    //Cap phat cho ma tran ke
    A = new int*[v];
    for (int i=0; i<v; i++)
	A[i] = new int[v];
    //Khoi tao danh sach ke
    AdjList = new list<int>[v];

    //Nhap so lieu tu file
    for (int i=0; i<v; i++)
	for (int j=0; j<v; j++)
	{
	    in >> A[i][j];
	    if (A[i][j] == 1)
		AdjList[i].push_back(j);
	}		

    //Kiem tra ma tran doi xung, gia do thi
    for (int i=0; i<v; i++)
    {
	if (A[i][i])
	    ward = false;
	for (int j=0; j<=i; j++)
	{
	    if (A[i][j] != A[j][i])
		ward = false;
	    if (A[i][j] == 1)
		e++;
	}
    }
    //Neu la gia do thi hoac khong phai do thi vo huong thi thoat
    assert(ward == true);
    in.close();
    
    //Khoi tao mang exam, co the khong can thiet
    exam = new bool[v];
    for (int i=0; i<v; i++)
	exam[i] = false;
}

//DFS tren 1 dinh
void GraphSearch::DFS(int vertice)
{
    cout << vertice << " -> ";
    exam[vertice] = true;

    for (list<int>::iterator i=AdjList[vertice].begin(); i != AdjList[vertice].end(); i++)
	if (!exam[*i])
	    DFS(*i);
    /*
    for (int i=0; i<v; i++)
	if (A[vertice][i] && !exam[i])
	    DFS(i);
    */
}
    
//DFS tren toan bo do thi
void GraphSearch::DFSGraph()
{
    for (int i=0; i<v; i++)
	exam[i] = false;
    for (int i=0; i<v; i++)
	if (!exam[i])
	    DFS(i);
}
    
//BFS tren 1 dinh
void GraphSearch::BFS(int vertice)
{
    queue<int> BFSQueue;

    BFSQueue.push(vertice);
    exam[vertice] = true;

    while (!BFSQueue.empty())
    {
		
	int a = BFSQueue.front();
	BFSQueue.pop();

	cout << a << " -> ";
	for (int i=0; i<v; i++)
	    if (A[a][i] && !exam[i])
	    {
		BFSQueue.push(i);
		exam[i] = true;
	    }
    }
}

void GraphSearch::BFSGraph()
{
    for (int i=0; i<v; i++)
	exam[i] = false;

    for (int i=0; i<v; i++)
	if (!exam[i])
	    BFS(i);
}
 

int main(int argc, char** argv)
{    
    GraphSearch a;
    a.DFSGraph();
    cout << endl;
    return 0;
}
