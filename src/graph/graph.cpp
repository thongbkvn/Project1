#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <queue>
#include <ctime>
#include <queue>
#include "graph.h"
using namespace std;

//Do thi vo huong
class GraphSearch : public graph
{
public:     
    //DFS tren 1 dinh
    void DFS(int vertice)
	{
	    cout << vertice + 1 << " -> "; //vertice+1 --> vertice
	    exam[vertice] = true;
	    for (int i=0; i<v; i++)
		if (A[vertice][i] && !exam[i])
		    DFS(i);
	}
    
    //DFS tren toan bo do thi
    void DFSGraph()
	{
	    for (int i=0; i<v; i++)
		exam[i] = false;
	    for (int i=0; i<v; i++)
		if (!exam[i])
		    DFS(i);
	}
    
    //BFS tren 1 dinh
    void BFS(int vertice)
	{
	    queue<int> BFSQueue;

	    BFSQueue.push(vertice);
	    exam[vertice] = true;

	    while (!BFSQueue.empty())
	    {
		
		int a = BFSQueue.front();
		BFSQueue.pop();

		cout << a+1 << " -> ";
		for (int i=0; i<v; i++)
		    if (A[a][i] && !exam[i])
		    {
			BFSQueue.push(i);
			exam[i] = true;
		    }
	    }
	}

    void BFSGraph()
	{
	    for (int i=0; i<v; i++)
		exam[i] = false;

	    for (int i=0; i<v; i++)
		if (!exam[i])
		    BFS(i);
	}
 
};

int main(int argc, char** argv)
{    
    graph a("input");
    a.BFSGraph();
    cout << endl;
    return 0;
}
