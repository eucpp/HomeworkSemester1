#include "graph.h"

Routes* createRoutes(int vertices)
{
	Routes *routes = new Routes;
	routes->vertices = vertices;
	routes->weight = new int[vertices + 1];
	routes->from = new int[vertices + 1];
	for (int i = 0; i <= routes->vertices; ++i)
	{
		routes->weight[i] = 0;
		routes->from[i] = 0;
	}
	return routes;
}
void clearRoutes(Routes *&routes)
{
	delete[] routes->weight;
	delete[] routes->from;
	delete routes;
	routes = NULL;
}

int getNearestVertex(Routes* vertices, unsigned int visited)
{
	int min = INT_MAX;
	int nearestVertex = 0;
	for (int i = 1; i <= vertices->vertices; ++i)
	{
		unsigned int mask = 1;
		mask <<= i - 1; 
		if ((vertices->weight[i] != 0) &&  (vertices->weight[i] < min) && !(mask & visited))
		{
			min = vertices->weight[i];
			nearestVertex = i;
		}
	}
	return nearestVertex;
}

Graph* createGraph(int n)
{
	Graph *graph = new Graph;
	graph->vertices = n;
	int **a = new int*[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		a[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	graph->a = a;
	return graph;
}
Graph* createGraph(char* filename)
{
	std::fstream in;
	in.open(filename);
	if (!in.is_open())
	{
		return NULL;
	}

	int vertices = 0;
	in >> vertices;
	int edges = 0;
	in >> edges;
	Graph *graph = createGraph(vertices);
	for (int k = 0; k < edges; ++k)
	{
		int i = 0;
		in >> i;
		int j = 0;
		in >> j;
		int weight = 0;
		in >> weight;
		if (i <= graph->vertices && j <= graph->vertices)
		{
			graph->a[i][j] = weight;
			graph->a[j][i] = weight;
		}
	}
	in.close();
	return graph;
}
Routes* getRoutes(Graph* graph, int vertex)
{
	if (graph->vertices > 32)
	{
		return NULL;
	}
	Routes *routes = createRoutes(graph->vertices);
	unsigned int endMask = 0;
	endMask = ~endMask;
	endMask >>= (32 - graph->vertices);
	unsigned int visited = 0;
	routes->weight[vertex] = 0;
	routes->from[vertex] = vertex;
	int current = vertex;
	while ((visited != endMask) && (current != 0))
	{
		int i = current;
		for (int j = 1; j <= graph->vertices; j++)
		{
			if (graph->a[i][j] == 0)
			{
				continue;
			}
			int weight = routes->weight[i] + graph->a[i][j];
			unsigned int jMask = 1;
			jMask <<= j - 1;
			if (!(jMask & visited) && ((weight < routes->weight[j]) || (routes->weight[j] == 0)))
			{
				routes->weight[j] = weight;
				routes->from[j] = current;
			}
		}
		unsigned int mask = 1;
		mask <<= current - 1;
		visited |= mask;
		current = getNearestVertex(routes, visited);
	}
	return routes;
}

void printGraph(Graph *graph, std::ostream &out)
{
	for (int i = 1; i <= graph->vertices; ++i)
	{
		out << " | ";
		for (int j = 1; j <= graph->vertices; ++j)
		{
			out << graph->a[i][j] << " | ";
		}
		out << std::endl;
	}
}

void clearGraph(Graph *&graph)
{
	for (int i = 0; i <= graph->vertices; i++)
	{
		delete[] graph->a[i];
	}
	delete[] graph->a;
	delete graph;
	graph = NULL;
}