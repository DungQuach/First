#include <iostream>
#include <vector>


class PriorityQueue
{
public:
	std::vector<std::pair<int,int>> heapTree;
	PriorityQueue(int,int);
	void siftdown(int);
	void heapify();
	std::pair<int,int> extractMin();
};





