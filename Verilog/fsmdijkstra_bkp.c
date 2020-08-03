#include <stdio.h> 
#include <limits.h> 
//#include "inputs.h"

#define V 9
#define TAM 3

void printPath(int parent[], int j) 
{ 
	
	// Base Case : If j is source 
	if (parent[j] == - 1) 
		return; 

	printPath(parent, parent[j]); 

	printf("%d ", j); 
} 


int dijkstra(int graph[V][V], int src, int dest, int * parent) 
{ 
	int dist[V]; 
	int sptSet[V]; 
	int min;

	//Inicializacão das memórias
	for (int i = 0; i < V; i++) 
	{ 
		parent[src] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = 0; 
	} 

	dist[src] = 0; 
	int u = 0;
 
	for (int count = 0; count < V - 1; count++) 
	{ 
		min = INT_MAX;
		for (int k = 0; k < V; k++) 
			if (sptSet[k] == 0 && 
					dist[k] <= min) 
				min = dist[k], u = k; 
		printf("u1 %d\n",u);

		sptSet[u] = 1; 
 
		for (int v = 0; v < V; v++) {
			if (!sptSet[v] && graph[u][v] && 
				dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
		}
	} 

	// print the constructed 
	// distance array 
	//printSolution(dist, V, parent, dest); 
	//printf("\n");
	//printf("DSITAANCIAA %d\n",dist[dest]);
	return dist[dest];
} 


int main() 
{ 
	// Parent array to store 
	// shortest path tree 
	int parent[V]; 

	// Let us create the example 
	// graph discussed above 
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
					{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
						{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
						{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
						{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
						{0, 0, 4, 0, 10, 0, 2, 0, 0}, 
						{0, 0, 0, 14, 0, 2, 0, 1, 6}, 
						{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
						{0, 0, 2, 0, 0, 0, 6, 7, 0} 
					}; 

	dijkstra(graph, 0, 4, parent); 
	printPath(parent, 4); 
	printf("\n");

	return 0; 
} 
