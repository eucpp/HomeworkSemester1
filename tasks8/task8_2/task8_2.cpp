#include <iostream>
#include <fstream>
#include "graph.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int maxFilename = 200;
	char filename[maxFilename];
	cout << "Enter filename (no more than " << maxFilename << " chars) with description of cities" << endl;
	cin >> filename;
	cout << endl;

	const int firstCity = 1;
	Graph *graph = createGraph(filename);
	if (graph != NULL)
	{
		Routes *routes = getRoutes(graph, firstCity);
		cout << "Occupied city: " << firstCity << "; " ;
		cout << "Distance: " << routes->weight[firstCity] << "; ";
		cout << "Route: " << firstCity << endl;
		unsigned int visited = 0;
		int nearestVertex = getNearestVertex(routes, visited);
		while (nearestVertex != 0)
		{
			cout << "Occupied city: " << nearestVertex << "; " ;
			cout << "Distance: " << routes->weight[nearestVertex] << "; ";
			cout << "Route: ";
			int from = routes->from[nearestVertex];
			while (from != firstCity)
			{
				cout << from << " <-- ";
				from = routes->from[from];
			}
			cout << from << endl;
			unsigned int mask = 1;
			mask <<= nearestVertex - 1;
			visited |= mask;
			nearestVertex = getNearestVertex(routes, visited);
		}
		clearRoutes(routes);
		clearGraph(graph);
	}
	else
	{
		cout << "Error. Cannot create graph";
		cout << endl;
	}


	int nothing = 0;
	cin >> nothing;
	cout << endl;
	return 0;
}