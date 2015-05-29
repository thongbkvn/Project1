#include "graph.h"
#include "dijkstra.h"
#include "bellmanford.h"
#include <iostream>
int main()
{
    Dijkstra a;
    BellmanFord b;
    a.dijkstraAlgorithm(0,3);
    a.printResult();
    b.bellmanFordAlgorithm(0,3);
    b.printResult();
    return 0;
}
