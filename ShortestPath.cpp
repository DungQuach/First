#include <iostream>
#include "PriorityQueue.h"
#include "AdjacencyList.h"
#include <vector>
#include <algorithm>
void printOptions();
std::vector<int> path;
int relax(std::pair<int, int>, std::pair<int, int>, int, std::vector<int>&);
void constructPath(int, int, std::vector<int>);

void constructPath(int target, int source, std::vector<int>pred)
{
	path.push_back(target);
	if (target == source)
		return;
	else
		constructPath(pred[target], source, pred);

}

int relax(std::pair<int, int> origin, std::pair<int, int> sample, int relaxedEdge, std::vector<int>&pred)
{

	int min = sample.second;
	if (min > origin.second + relaxedEdge)
	{
		pred[sample.first] = origin.first;
		min = origin.second + relaxedEdge;
	}
	return min;
}

void printOptions()
{
	std::cout << "Available Options: " << std::endl;
	std::cout << "1.Add edge " << std::endl;
	std::cout << "2.Find the shortest path " << std::endl;
	std::cout << "Your choice: " << std::endl;
}
void main(void)
{
	int vertices, source, target;
	int select = 1;
	std::vector<int> pred;
	std::cout << "Number of vertices: ";
	std::cin >> vertices;
	for (int x = 0; x < vertices; x++)
	{
		pred.push_back(0);
	}
	std::cout << "The source: ";
	std::cin >> source;
	std::cout << "The target: ";
	std::cin >> target;
	PriorityQueue priorityQueue(source, vertices);
	AdjacencyList control(vertices);
	std::vector<int> keepTrack;
	while (select != 2)
	{
		printOptions();
		std::cin >> select;
		switch (select)
		{
		case 1:
		{
			int start, end, weight;
			std::cout << "Start vertex: ";
			std::cin >> start;
			std::cout << "End vertex: ";
			std::cin >> end;
			std::cout << "Weight: ";
			std::cin >> weight;
			control.addEdge(start, end, weight);
			break;
		}
		case 2:
		{
			while (priorityQueue.heapTree.size() != 0 && !(std::find(keepTrack.begin(), keepTrack.end(), target) != keepTrack.end()))
			{
				//extract min from heap
				std::pair<int, int> result = priorityQueue.extractMin();
				// push to S
				keepTrack.push_back(result.first);
				//check adjacency list to relax
				for (int i = 0; i < control.adjacencyList[result.first].size(); i++)
				{
					std::pair<int, int> indicator = control.adjacencyList[result.first][i];
					int t = indicator.first;
					if (std::find(keepTrack.begin(), keepTrack.end(), t) != keepTrack.end())
					{
						continue;
					}
					auto needUpdated = std::find_if(priorityQueue.heapTree.begin(),
						priorityQueue.heapTree.end(),
						[&t](const std::pair<int, int> val)
					{ return val.first == t; });
					needUpdated->second = relax(result, *needUpdated, indicator.second, pred);
					priorityQueue.siftdown(0);
				}
			}
			break;
		}
		}
	}
	std::cout << "The path: " << std::endl;
	constructPath(target, source, pred);
	while (!path.empty())
	{
		std::cout << path.back() << " ";
		path.pop_back();
	}
	system("pause");
}
