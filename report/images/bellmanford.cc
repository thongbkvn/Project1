#include "bellmanford.h"
#include "graph.h"
#include <iostream>

void BellmanFord::printResult()
{
    if (d[t] == MAXW)
	std::cout << "\nKhong co duong di tu " << s << " den " << t << std::endl;
    else
    {
	std::cout << "\nKhoang cach tu " << s << " den " << t << " la: " << d[t] << std::endl;
	std::cout << "Duong di ngan nhat tu " << s << " den " << t << std::endl;


	int i = t;
	while (i != s)
	{
	    std::cout << i << " <- ";
	    i = Truoc[i];
	}
	std::cout << s << std::endl;
    }
}


void BellmanFord::bellmanFordAlgorithm(int s, int t)
{
    this->s = s, this->t = t;

    int u, v, count;
    bool stop;
    //Khoi tao
    for (v=1; v<V; v++)
	d[v] = MAXW;
    d[s] = 0;

    for (count = 0; count < V-1; count++)
    {
	stop = true;
	for (u=0; u<V; u++)
	    for (v=0; v<V; v++)
		if (d[v] > d[u] + A[u][v])
		{
		    d[v] = d[u] + A[u][v];
		    Truoc[v] = u;
		    stop = false;
		}
	if (stop)
	    break;
    }
}
