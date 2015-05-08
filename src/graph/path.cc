#include "graph.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <iomanip>
using namespace std;

class path : public graph
{
    int *trace;
public:

    void DFS(int vertice)
	{
	    for (list<int>::iterator i=AdjList[vertice].begin(); i!=AdjList[vertice].end(); i++)
		if (trace[*i] == -2)
		{
		    trace[*i] = vertice;
		    DFS(*i);
		}
	}


    int DFSPath(int src, int dst)
	{
	    stack<int> path_stack;
	    int a = dst;
	    //Khoi tao mang trace
	    trace = new int[v];
	    for (int i=0; i<v; i++)
		trace[i] = -2;


	    trace[src] = -1;
	    DFS(src);

	    //Neu khong di toi duoc dich
	    if (trace[dst] == 0)
		return 0;
	    while (a != src)
	    {
		cout << a << " <- "; //Van de dinh bat dau tu 0 va tu 1
		a = trace[a]; 
	    }
	    cout << src;

	    delete trace;
	    return 1;
	}

    void BFS(int vertice)
	{
	    queue<int> BFSQueue;
	    BFSQueue.push(vertice);
	    trace[vertice] = -1;

	    while (!BFSQueue.empty())
	    {
		int a = BFSQueue.front();
		BFSQueue.pop();

		for (list<int>::iterator i=AdjList[a].begin(); i!=AdjList[a].end(); i++)
		    if (trace[*i] == -2)
		    {
			trace[*i] = a;
			BFSQueue.push(*i);
		    }
			
	    }
	}
    int BFSPath(int src, int dst)
	{
	    int a = dst;
	    
	    //Khoi tao mang trace
	    trace = new int[v];
	    for (int i=0; i<v; i++)
		trace[i] = -2;

	    BFS(src);
	    
	    if (trace[dst] == 0)
		return 0;

	    while (a != src)
	    {
		cout << a << " <- ";
		a = trace[a];
	    }
	    cout << src;
	    delete trace;
	    return 1;
	}
	
};

int main()
{
    path a;
    a.DFSPath(0, 8);
    a.BFSPath(0, 8);
    cout << endl;
    return 0;
}
