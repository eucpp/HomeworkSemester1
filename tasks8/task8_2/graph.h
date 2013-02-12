#pragma once

#include <iostream>
#include <fstream>
#include <limits.h>

struct Graph
{
	int vertices;
	int **a;
};
struct Routes
{
	int vertices;
	int *weight;
	int *from;
};

Graph* createGraph(int n);
Graph* createGraph(char* filename);
Routes* getRoutes(Graph* graph, int vertex);
void clearGraph(Graph *&graph);
void printGraph(Graph *graph, std::ostream &out);

Routes* createRoutes(int vertices);
int getNearestVertex(Routes* vertices, unsigned int visited);
void clearRoutes(Routes *&routes);
