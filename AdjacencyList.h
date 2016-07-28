
#include <iostream>
#include <vector>

class AdjacencyList
{	
	public:
	std::vector<std::vector<std::pair<int,int>>> adjacencyList;
	AdjacencyList(int);
	void addEdge(int ,int , int );
};


