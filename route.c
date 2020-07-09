#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 16
#define TAM 4

int printPath(int parent[], int j) 
{ 
//	PTAM += 1;
	// Base Case : If j is source 
	int contador = 0;

	while(parent[j] != -1){
		contador ++;
		//printf("%d ", j);
		j = parent[j];
	}
	return contador;
} 

int minDistance(int dist[], int sptSet[]) 
{ 
	
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == 0 && 
				dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[], int n, int parent[], int dest) 
{ 
	int src = 1; 
	printf("Vertex\t Distance\tPath"); 
	//for (int i = 1; i < V; i++) 
	//{ 
		printf("\n%d -> %d \t\t %d\t\t%d ", src, dest, dist[dest], src); 
		//printPath(parent, dest); 
	///} 
} 

void dijkstra(int graph[V][V], int src, int dest, int * parent) 
{ 
	int dist[V]; 
	int sptSet[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[src] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = 0; 
	} 

	dist[src] = 0; 
 
	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minDistance(dist, sptSet); 

		sptSet[u] = 1; 
 
		for (int v = 0; v < V; v++) 
			if (!sptSet[v] && graph[u][v] && 
				dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 

	// print the constructed 
	// distance array 
//	printSolution(dist, V, parent, dest); 
} 

int main(){
	int FLAG = 0;
	int parent[V];

	int i,j;
	int m[V][V];
	int m_copia[V][V];

	int edges = 12;


	//E2
	//int e_a[] = {1, 2, 3, 4, 5, 6, 9};
	//int e_b[] = {6, 6, 6, 6, 7, 5, 5};

	int e_a[] = {1, 2, 2, 3, 3, 7, 6, 5, 5, 4, 8, 9};
	int e_b[] = {4, 4, 5, 5, 6, 6, 9, 9, 8, 8, 10, 10};

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];

	int ALU[V];
	int ALUREG[V];	
	int BYPASS[V];
	int ORIGEM_DF[V][V];


	//PRIMEIRO EXEMPLO
	/*int a[] = {0, 3, 1, 5, 2};
	int b[] = {1, 1, 2, 2, 8};*/
	
	//matriz resultado do placement
	//E2
	//int grid[] = {1, 2, 8, 3, 6, 4, 9, 5, 7};
	int grid[] = {1, 4, 2, 3, 255, 8, 5, 6, 255, 10, 9, 7, 255, 255, 255, 255};

	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				//printf("%d\n", i);
			}
		}
	}
	//printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				//printf("%d\n", i);
			}
		}
	}	


	for(i=0; i<V; i++){
		//indice_e[i] = 0;
		//indice_s[i] = 0;
		ALU[i] = 0;
		ALUREG[i] = 0;
		BYPASS[i] = 0;
		//printf("BYPASS %d = %d", i, BYPASS[i]);
		for(j=0; j<V; j++){
			m[i][j] = 0;
			m_copia[i][j] = 0;
			ORIGEM_DF[i][j] = -1;
			//printf("%d",m);
		}
	}

	int peso = 100;
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(i<TAM-1 & j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = peso; 
				m[i*TAM+(j+1)][i*TAM+j] = peso; 
				m[i*TAM+j][(i+1)*TAM+j] = peso; 
				m[(i+1)*TAM+j][i*TAM+j] = peso; 
			}else if(i<TAM-1){
				m[i*TAM+j][(i+1)*TAM+j] = peso; 
				m[(i+1)*TAM+j][i*TAM+j] = peso; 
			}else if(j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = peso; 
				m[i*TAM+(j+1)][i*TAM+j] = peso; 
			}
		}
	}

	for(i=0; i<V; i++)
		for(j=0; j<V; j++)
			m_copia[i][j] = m[i][j];

	/*for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	int jafoi[edges];
	for(i=0; i<edges; i++)
		jafoi[i] = 0;

	for(i=0; i<edges; i++){
		A = a[i]; //origem no dataflow
		B = b[i]; //destino no dataflow

		printf("A%d B%d",A,B);
		dijkstra(m, A, B, parent);
		int cont = printPath(parent, B);
		printf("\n");

		printf("%d \n",cont);
		//PASSO1: faz roteamento trivial
		if(cont == 1){	
			jafoi[i] = 1;		
			j = 0;
			while(1){
				if(j ==0 ){
					destino = B;
				}else{
					destino = origem;
				}

				origem = parent[destino];
				if(origem == -1)
					break;

				printf("origem=%d dest=%d\n",origem,destino);

				if(destino == origem-1){
					entradas[destino][0] = origem;
					saidas[origem][2] = destino;
				}else if(destino == origem-TAM){
					entradas[destino][1] = origem; 
					saidas[origem][3] = destino; 
				}else if(destino == origem+1){
					entradas[destino][2] = origem; 
					saidas[origem][0] = destino; 
				}else if(destino == origem+TAM){
					entradas[destino][3] = origem;
					saidas[origem][1] = destino;  
				}else{
					printf("DEU RUIM\n");
					FLAG = 1;
					//exit(1);
					break;
				}
				//aumenta peso das arestas que levam a esse mesmo destino, SE != ZERO
				for(int aux=0; aux<V;aux++)
					if(m[aux][destino] != 0)
						m[aux][destino]++;
				//marca ALU como usada
				ALU[destino] = 1; 
				//remove aresta usada
				//printf("\n od %d %d\n",origem,destino);
				m[origem][destino] = 0;
				//salva a origem no dataflow dessa aresta roteada em cada um dos PEs da rota
				ORIGEM_DF[origem][destino] = A;

				j++;		
			}
			if(FLAG == 1)
				break;
			printf("\n");
		}

	}
	printf("INICIA PASSO 2\n");
	for(int u=0; u<V; u++)
		for(int v=0; v<V; v++)
			m_copia[u][v] = m[u][v];

	for(i=0; i<edges; i++){
		int flag_multicast = 0;
		//Não refazer dijkstra para arestas ja roteadas
		while(jafoi[i] == 1)
			i++;
		if(i >= edges)
			break;

		//printf("VALOR DE i %d\n", i);

		A = a[i]; //origem no dataflow
		B = b[i]; //destino no dataflow

		for(int u=0; u<V; u++){
			for(int v=0; v<V; v++){
				if(ORIGEM_DF[u][v] == A){
					m[u][v] = 100;
					flag_multicast = 1;
				}
			}
		}		

		printf("A%d B%d",A,B);
		dijkstra(m, A, B, parent);
		int cont = printPath(parent, B);
		printf("\n");

		printf("%d \n",cont);
		//PASSO2: faz roteamento não-trivial
		if(cont != 1){	
			j = 0;
			while(1){
				if(j ==0 ){
					destino = B;
				}else{
					destino = origem;
				}

				origem = parent[destino];
				if(origem == -1)
					break;

				printf("origem=%d dest=%d\n",origem,destino);

				if(destino == origem-1){
					entradas[destino][0] = origem;
					saidas[origem][2] = destino;
				}else if(destino == origem-TAM){
					entradas[destino][1] = origem; 
					saidas[origem][3] = destino; 
				}else if(destino == origem+1){
					entradas[destino][2] = origem; 
					saidas[origem][0] = destino; 
				}else if(destino == origem+TAM){
					entradas[destino][3] = origem;
					saidas[origem][1] = destino;  
				}else{
					printf("DEU RUIM\n");
					FLAG = 1;
					//exit(1);
					break;
				}

				//marca ALU como usada
				//printf("%d %d %d \n",ALUREG[destino], BYPASS[destino], destino);
				if(!flag_multicast){
					if(destino == B){
						printf("dest e B \n");
						if(ALUREG[destino] == 1){
							printf("DEU RUIM B\n");
							FLAG = 1;
							break;
						}else
							ALU[destino] = 1;
					}else if(BYPASS[destino] == 0){
						BYPASS[destino] = 1;
					}else if(ALUREG[destino] == 0 && ALU[destino] == 0){
						ALUREG[destino] = 1;
					}
					else{
						printf("DEU RUIM bypassXalureg\n");
						FLAG = 1;
						break;
					}
				}
					

				//aumenta peso das arestas que levam a esse mesmo destino
				for(int aux=0; aux<V;aux++)
					m[aux][destino]++;				 
				//remove aresta usada
				m[origem][destino] = 0;
				//salva a origem no dataflow dessa aresta roteada em cada um dos PEs da rota
				ORIGEM_DF[origem][destino] = A;
				//printf("A = %d\n", A);

				if(flag_multicast){
					for(int u=0; u<V; u++){
						for(int v=0; v<V; v++){
							//essa arestas sempre sao arestas usadas
							if(ORIGEM_DF[u][v] == A)
								m[u][v] = 0;
						}
					}
				}

				j++;		
			}
			if(FLAG == 1)
				break;
			printf("\n");
		}

	}


}




