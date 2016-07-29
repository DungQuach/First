#include <iostream>
#include "PriorityQueue.h"
#include "AdjacencyList.h"
#include <vector>
#include <algorithm>
void printOptions();
int relax(std::pair<int,int>,std::pair<int,int>,int);

int relax(std::pair<int,int> origin,std::pair<int,int> sample,int relaxedEdge)
{
	int min = sample.second;
	if (min > origin.second + relaxedEdge)
		min = origin.second + relaxedEdge;
	return min;
}

void printOptions()
{
		std::cout<<"Available Options: "<<std::endl;
		std::cout<<"1.Add edge "<<std::endl;
		std::cout<<"2.Find the shortest path "<<std::endl;
		std::cout<<"Your choice: "<<std::endl;
}
void main(void)
{
	int vertices,source;
	int select = 1;
	std::cout<<"Number of vertices: ";
	std::cin>>vertices;
	std::cout<<"The source: ";
	std::cin>>source;
	PriorityQueue priorityQueue(source,vertices);
	AdjacencyList control(vertices);
	std::vector<int> keepTrack;
	while(select!=2)
	{
	printOptions();
	std::cin>>select;
	switch(select)
	{
	case 1:
		{
			int start,end,weight;
			std::cout<<"Start vertex: ";
			std::cin>>start;
			std::cout<<"End vertex: ";
			std::cin>>end;
			std::cout<<"Weight: ";
			std::cin>>weight;
			control.addEdge(start,end,weight);
			break;
		}
	case 2:
		{
			while(priorityQueue.heapTree.size() != 0)
			{
				//extract min from heap
				std::pair<int,int> result = priorityQueue.extractMin();
				// push to S
				keepTrack.push_back(result.first);
				//check adjacency list to relax
				for(int i = 0; i < control.adjacencyList[result.first].size();i++)
				{
					std::pair<int,int> indicator = control.adjacencyList[result.first][i];
					int t = indicator.first;
					auto needUpdated = std::find_if(priorityQueue.heapTree.begin(),
													priorityQueue.heapTree.end(),
													[&t](const std::pair<int,int> val)
													{ return val.first == t;});
					needUpdated->second = relax(result,*needUpdated,indicator.second);
					priorityQueue.siftdown(0);
				}
			}
			break;
		}
	}
	}
	std::cout << "The path: " << std::endl;
	for (int i =0; i< keepTrack.size();i++)
	{
		std::cout<<keepTrack[i] <<" ";
	}
	system("pause");
}
