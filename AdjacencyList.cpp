
#include <iostream>
#include <vector>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int vertices)
{
	adjacencyList = std::vector<std::vector<std::pair<int,int>>>(vertices);
}

void AdjacencyList::addEdge(int startV,int endV, int weight)
{
	adjacencyList[startV].push_back(std::make_pair(endV,weight));
}


