#ifndef GRAPH_H_
#define GRAPH_H_

#define MAXV 100
class Graph
{
public:
    int V; //So dinh, so canh
    int A[MAXV][MAXV]; //Ma tran trong so

    Graph(const char* filename="adjmatrix_input.txt");
    void info();
};

#endif
