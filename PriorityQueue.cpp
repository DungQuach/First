#include "PriorityQueue.h"
#include <iostream>
#include <vector>



void PriorityQueue::siftdown(int i)
	{
		int n = heapTree.size();
		int leftChild = 2*i +1;
		int rightChild = 2*i + 2;
		if(leftChild>= n)
			return;
		int minIndex = i;
		if (heapTree[i].second > heapTree[leftChild].second)
			minIndex = leftChild;
		if ((rightChild < n) && (heapTree[minIndex].second > heapTree[rightChild].second))
			minIndex = rightChild;
		if (minIndex != i)
		{
			std::pair<int,int> temp = heapTree[i];
			heapTree[i] = heapTree[minIndex];
			heapTree[minIndex] = temp;
			siftdown(minIndex);
		}
	}

void PriorityQueue::heapify()
	{
		int n = heapTree.size();
		for (int a = (n-1)/2; a >= 0 ;a--)
		{
			siftdown(a);
		}
	}

PriorityQueue::PriorityQueue(int source,int vertices)
{
	heapTree = std::vector<std::pair<int,int>>(vertices);
	for (int x=0;x<vertices;x++)
	{
		heapTree[x].first = x;
		heapTree[x].second = 50000;
	}
	heapTree[source].second = 0;
	heapify();
}

std::pair<int,int> PriorityQueue::extractMin()
{
	int n = heapTree.size();
	std::pair<int,int> result = heapTree[0];
	heapTree[0] = heapTree[n-1];
	heapTree.resize(n-1);
	siftdown(0);
	return result;
}






