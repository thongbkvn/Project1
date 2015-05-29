#include "dijkstra.h"
#include <iostream>


void Dijkstra::printResult()
{
    if (d[t] >= MAXW)
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



void Dijkstra::dijkstraAlgorithm(int s, int t)
{
    this->s = s; this->t = t;
    int minp, u, v;
    //Khoi tao nhan
    for (v=1; v<V; v++)
    {
	d[v] = A[s][v];
	Truoc[v] = s;
	final[v] = false;
    }

    Truoc[s] = -1;
    d[s] = 0;
    final[s] = true;

    while (!final[t])
    {
	//Tim dinh co nhan tam thoi nho nhat
	minp = MAXW;
	u = -1;
	for (v=0; v<V; v++)
	    if (!final[v] && minp>d[v])
	    {
		u = v;
		minp = d[v];
	    }
	final[u] = true;
	
	if (u==-1)
	    break;
	
	for (v=0; v<V; v++)
	    if (!final[v] && (d[v] > d[u] + A[u][v]))
	    {
		d[v] = d[u] + A[u][v];
		Truoc[v] = u;
	    }
		
    }
}
	
