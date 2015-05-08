#include "graph.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
using namespace std;

class connection : public graph
{
    int inconnect, *index;
public:

    void DFS(int vertice)
	{
	    index[vertice] = inconnect;
	    for (list<int>::iterator i=AdjList[vertice].begin(); i!=AdjList[vertice].end(); i++)
		if (index[*i] == -2)
		    DFS(*i);
	}

    void DFSConnect()
	{
	    index = new int[v];
	    for (int i=0; i<v; i++)
		index[i] = 0;
	    inconnect = 0;

	    for (int i=0; i<v; i++)
		if (!index[i])
		{
		    inconnect++;
		    DFS(i);
		}

	    for (int i=0; i<v; i++)
		cout << index[i] << ' ';
	    delete [] index;
	}

};

int main()
{
    connection a;
    a.DFSConnect();

    cout << endl;
    return 0;
}
