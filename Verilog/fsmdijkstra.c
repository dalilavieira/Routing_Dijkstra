#include <stdio.h> 
#include <limits.h> 
//#include "inputs.h"

#define V 9
#define TAM 3

//dijkstra tem 19 estados

void printPath(int parent[], int j) 
{ 
	
	// Base Case : If j is source 
	if (parent[j] == - 1) 
		return; 

	printPath(parent, parent[j]); 

	printf(" %d ", j); 
} 


int dijkstra(int graph[V*V], int src, int dest, int * parent) 
{ 
	int dist[V]; 
	int sptSet[V]; 

	//Inicializacão das memórias
	for (int i = 0; i < V; i++) 
	{ 
		parent[src] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = 0; 
	} 
	
	int u, k, v, estado =0, count, min;
	int sptSetout, distout, distvout, distuout, graphindex, graphout;

	while(1){
		//printf("count %d\n",count);
		/*printf("v %d\n",v);
		printf("k %d\n",k);*/
		//printf("state %d\n",estado);
		if(count == V-1){
			printf("saindo\n");
			break;
			//exit(1);
		}
	
		switch(estado){
		case 0:
			dist[src] = 0; 
			estado = 5;
		break;
		case 5:
			u = 0;
			count = 0;
			estado = 1;
		break;
		case 1:
			min = INT_MAX;
			k = 0;
			v = 0;
			estado = 10;
		break;
		case 10:
			if(k < V)
				estado = 8;
			else	
				estado = 3;				
		break;
		case 8: //le sptSet
			sptSetout = sptSet[k];
			estado = 9;
		break;
		case 9: //le dist
			distout = dist[k];
			estado = 2;
		break;
		case 2:
			if (sptSetout == 0 && distout <= min) {
				min = distout;
				u = k; 
			//	printf("u1 %d\n",u);
			}
			k = k + 1;
			estado = 10;
		break;
		case 3:
			sptSet[u] = 1; 
			estado = 11;
		break;
		case 11:
			if(v < V)
				estado = 12;
			else
				estado = 6;
		break;
		case 12:
			distvout = dist[v];
			estado = 13;
		break;
		case 13:
			distuout = dist[u];
			estado = 14;
		break;
		case 14:
			sptSetout = sptSet[v];
			estado = 15;
		break;
		case 15:
			graphindex = u+V*v;
			estado = 16;
		break;
		case 16:
			graphout = graph[graphindex];
			estado = 4;
		break;
		case 4:
			if (!sptSetout && graphout && distuout + graphout < distvout){ 
				estado =  18;
			}else
				estado = 17;
		break;
		case 18:
			parent[v] = u; 

			estado = 19;
		break;
		case 19:
			dist[v] = distuout + graphout; 
			estado = 17;
		break;
		case 17:
			v = v + 1;
			estado = 11;
		break;
		case 6:
			count = count + 1;
			if(count == V-1){ //criar estado para isso
				printf("saindo %d\n", dist[dest]);
			}				
			estado = 1;
		break;
		}
	}

	return dist[dest];
} 


int main() 
{ 
	// Parent array to store 
	// shortest path tree 
	int parent[V]; 

	// Let us create the example 
	// graph discussed above 
	int graph[V*V] = {0, 4, 0, 0, 0, 0, 0, 8, 0, 
					4, 0, 8, 0, 0, 0, 0, 11, 0, 
						0, 8, 0, 7, 0, 4, 0, 0, 2, 
						0, 0, 7, 0, 9, 14, 0, 0, 0, 
						0, 0, 0, 9, 0, 10, 0, 0, 0, 
						0, 0, 4, 0, 10, 0, 2, 0, 0, 
						0, 0, 0, 14, 0, 2, 0, 1, 6, 
						8, 11, 0, 0, 0, 0, 1, 0, 7, 
						0, 0, 2, 0, 0, 0, 6, 7, 0 
					}; 

	dijkstra(graph, 0, 4, parent); 
	printPath(parent, 4); 
	printf("\n");

	return 0; 
} 
