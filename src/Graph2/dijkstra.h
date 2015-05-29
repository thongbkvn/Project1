#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "graph.h"
#define MAXW 1000

class Dijkstra:public Graph
{
private:
    int s, t;
    
    int Truoc[MAXV];
    int d[MAXV];
    bool final[MAXV];
public:
    void printResult();
    void dijkstraAlgorithm(int s, int t);
	
    
};

#endif
