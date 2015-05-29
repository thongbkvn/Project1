#ifndef BELLMANFORD_H_
#define BELLMANFORD_H_

#include "graph.h"

#define MAXW 1000

class BellmanFord:public Graph
{
private:
    int s, t;

    int Truoc[MAXV];
    int d[MAXV];
public:
    void printResult();
    void bellmanFordAlgorithm(int s, int t);
};

#endif //BELLMANFORD_H_
