#include "graph.h"
#include <fstream>
#include <iostream>
#include <iomanip>

Graph::Graph(const char* filename)
{
    std::ifstream in(filename);
    in >> V;

    for (int i=0; i<V; i++)
	for (int j=0; j<V; j++)
	    in >> A[i][j];
}

void Graph::info()
{
    std::cout << "So dinh cua do thi: " << V << std::endl;

    for (int i=0; i<V; i++)
    {
	for (int j=0; j<V; j++)
	    std::cout << std::setw(4) << A[i][j];
	std::cout << std::endl;
    }
}
