#include "graph.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <cassert>
#include <iomanip>
using namespace std;

graph::graph(const char* filename)
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
}

void graph::adj_list()
{
    
    for (int i=0; i<v; i++)
    {
	for (list<int>::iterator j = AdjList[i].begin(); j != AdjList[i].end(); j++)
	    cout << " -> " << *j+1;
	cout << endl;
    }
}

void graph::adj_matrix()
{
    for (int i=0; i<v; i++)
    {
	for (int j=0; j<v; j++)
	    cout << setw(3) << A[i][j];
	cout << endl;
    }
}
