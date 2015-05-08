#ifndef GRAPH_H_
#define GRAPH_H_

#include <queue>
#include <list>
class graph
{
public:
    int v,  e; //So dinh, so canh
    int **A; //Ma tran ke
    std::list<int> *AdjList;

    graph(const char* filename="adjacent_matrix_input.txt");
    void adj_list();
    void adj_matrix();
};

#endif
