#ifndef GRAPH_SEARCH_H_
#define GRAPH_SEARCH_H_

#include "graph.h"
class GraphSearch : public graph
{
    bool *exam;
public:
    GraphSearch(const char* filename="adjacent_matrix_input.txt");
    void DFS(int vertice);
    void DFSGraph();
    void BFS(int vertice);
    void BFSGraph();
};

#endif //GRAPH_SEARCH_H_
