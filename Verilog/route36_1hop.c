#include <stdio.h> 
#include <limits.h> 
#include "inputs.h"

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)

#define V 400
#define TAM 20

int grid[V];
int ret;

void bubble(int *ordena, int*a, int *b, int *jafoi){
	int aux1, aux2, aux3, aux4;
	for(int u=0; u<edges; u++){
		for(int v=0; v<edges; v++){
			if(ordena[u] < ordena[v]){
				aux1 = ordena[v];
				ordena[v] = ordena[u];
				ordena[u] =  aux1;

				aux2 = a[v];
				a[v] = a[u];
				a[u] = aux2;

				aux3 = b[v];
				b[v] = b[u];
				b[u] = aux3;
		
				aux4 = jafoi[v];
				jafoi[v] = jafoi[u];
				jafoi[u] = aux4;
			}
		}
	}
}

int printPath(int parent[], int j) 
{ 
//	PTAM += 1;
	// Base Case : If j is source 
	int contador = 0;

	while(parent[j] != -1){
		contador ++;
		//printf("%d ", j);
		//printf("%d\n",contador);
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

int dijkstra(int graph[V][V], int src, int dest, int * parent) 
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

	return dist[dest];
} 

int main(){
	int ordena[edges];
	int FLAG = 0;
	int parent[V];

	int i,j;
	int m[V][V];


	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];

	int ALU[V];
	int ALUREG[V];	
	int BYPASS[V];
	int ORIGEM_DF[V][V];

	for (int j=0; j<TAM; j++){
		for (int i=0; i<TAM; i++){
			grid[j*TAM+i] = 255;
			if(i >= 5 && j >= 5 && i < 5+tam && j < 5+tam)
				grid[j*TAM+i] = place[(j-5)*tam+(i-5)];
		}
	}
	
	for (int j=0; j<TAM; j++){
		for (int i=0; i<TAM; i++){
			printf("%d ",grid[j*TAM+i]);

		}
		printf("\n");
	}

	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				//printf("II %d\n", e_ a[j]);
			}
		}
	}
	//printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				//printf("jj %d\n", i);
			}
		}
	}

	//TODO VERTICE USA ALU
	for (int j=0; j<edges; j++){
		ALU[b[j]] = 1;
		ALU[a[j]] = 1;
		printf("%d %d\n", b[j], a[j]);
	}


	for(i=0; i<V; i++){
		//indice_e[i] = 0;
		//indice_s[i] = 0;
		//ALU[i] = 0;
		ALUREG[i] = 0;
		BYPASS[i] = 0;
		//printf("BYPASS %d = %d", i, BYPASS[i]);
		for(j=0; j<V; j++){
			m[i][j] = 0;
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
			if(i<TAM-2 & j<TAM-2){
				m[i*TAM+j][i*TAM+(j+2)] = peso; 
				m[i*TAM+(j+2)][i*TAM+j] = peso; 
				m[i*TAM+j][(i+2)*TAM+j] = peso; 
				m[(i+2)*TAM+j][i*TAM+j] = peso; 
			}else if(i<TAM-2){
				m[i*TAM+j][(i+2)*TAM+j] = peso; 
				m[(i+2)*TAM+j][i*TAM+j] = peso; 
			}else if(j<TAM-2){
				m[i*TAM+j][i*TAM+(j+2)] = peso; 
				m[i*TAM+(j+2)][i*TAM+j] = peso; 
			}
		}
	}

	int jafoi[edges];
	for(i=0; i<edges; i++)
		jafoi[i] = 0;

	//for(i=0; i<edges; i++){
	int cont, estado = 0, END = 0;
	i = 0; 
	while(1){
		if(END == 1) break;
		switch(estado){
			case 0:
				if(i<edges)
					estado = 1;
				else
					END = 1;
			break;
			case 2:
				i = i + 1;
				estado = 0;
			break;
			case 1:
				A = a[i]; //origem no dataflow
				B = b[i]; //destino no dataflow

				printf("A%d B%d",A,B);
				ret = dijkstra(m, A, B, parent);
				printf("\n");
				estado = 3;
			break;
			case 3:
				printf("ret %d",ret);
				if(ret > V*1000 || ret < -V*1000 ){
					printf("distancia infinita no dijkstra\n");
					printf("DEU RUIM\n");
					//break;
					return 1;// TODO: manda pra saida
				}
				estado = 4;
			break;
			case 4:
				cont = printPath(parent, B);
				ordena[i] = cont;
				printf("\n\n %d %d %d \n",cont, A, B);
				//PASSO1: faz roteamento trivial
				estado = 5;
			break;
			case 5:
				if(cont == 1)
					estado = 6;
				else
					estado = 2;	
			break;
			case 6:
				jafoi[i] = 1;		
				j = 0;
				estado = 7;
			break;
			case 7:
				if(j ==0 ){
					destino = B;
				}else{
					destino = origem;
				}
				estado = 9;
			break;
			case 9:
				origem = parent[destino];
				if(origem == -1){
					estado = 8;
					break; //vai pra 8
				}
				estado = 10;
			break;
			case 10:
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
					estado = 8;
					break; //vai pra 8
				}
				estado = 11;
			break;
			case 11:
				//aumenta peso das arestas que levam a esse mesmo destino, SE != ZERO
				for(int aux=0; aux<V;aux++) //TODO: desmembrar em estados
					if(m[aux][destino] != 0)
						m[aux][destino]++;

				estado = 12;
			break;
			case 12:
				//marca ALU como usada
				ALU[destino] = 1; 
				//remove aresta usada
				//printf("\n od %d %d\n",origem,destino);
				m[origem][destino] = 0;
				//salva a origem no dataflow dessa aresta roteada em cada um dos PEs da rota
				ORIGEM_DF[origem][destino] = A;

				j++;	
				estado = 7;	
			break;
			case 8:
				if(FLAG == 1){
					END = 1;
					estado = 2;
					break;
				}
				printf("\n");
	
				estado = 2;
			break;
		}

	}

	//ordena as arestas para o passo 2
	bubble(ordena, a, b, jafoi);	

	printf("INICIA PASSO 2\n");


	estado = 13;
	int v = 0, w = 0;
	END = 0;

	while(1){
		if(END == 1) break;
		switch(estado){
		case 14:
			END = 1;
		break;
		case 13:
			if(v<edges)
				estado = 15;
			else
				estado = 14;
		break;
		case 16:
			v++;
			estado = 13;
		break;
		case 15:
			//ordena as arestas 
			bubble(ordena, a, b, jafoi);	
			estado = 18;	
		break;
		case 18:
			//Não refazer dijkstra para arestas ja roteadas
			printf("\nAi %d Bi %d foi %d i%d \n",a[v],b[v],jafoi[v], v);
			int flag = 0;
			estado = 22;
		break;
		case 22:
			if(jafoi[v] == 1){
				v++;
				estado = 23;
			}else
				estado = 21;
		break;
		break;
		case 23:
			if(v >= edges){
				flag = 1;
				estado = 21;
			}
			else
				estado = 22;
		break;
		case 21:
			if(flag == 1)
				estado = 14;
			else
				estado = 19;
		break;
		case 19:
			printf("VALOR DE i %d a%d b%d jafoi%d\n", v,a[v],b[v],jafoi[v]);

			A = a[v]; //origem no dataflow
			B = b[v]; //destino no dataflow		

			printf("A%d B%d",A,B);
			printf("chaama dijkistra\n");
			ret = dijkstra(m, A, B, parent);
			printf("ret %d\n", ret);

			printf("\n");
			if(ret > V*1000 || ret < -V*1000 ){
					printf("distancia infinita no dijkstra\n");
					printf("DEU RUIM\n");
					estado = 14;
					break;
			}
			estado = 20;
		break;
		case 20:
			cont = printPath(parent, B);
			ordena[v] = cont;
			//printf("conta \n");
			printf("\n");
			estado = 17;
		break;
		case 17:
			//PASSO2: faz roteamento não-trivial
			if(cont != 1){	
				w = 0;
				estado = 24;
			}else 
				estado = 16;
		break;
		case 24:
			if(w == 0){
				destino = B;
			}else{
				destino = origem;
			}
			estado = 27;
		break;
		case 27:
			origem = parent[destino];
			estado = 28;
		break;
		case 28:
			if(origem == -1){
				estado = 25;
				break;
			}
			estado = 26;
		break;
		case 26:
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
				estado = 25;
				break;
			}
			estado = 29;
		break;
		case 29:
			//printf("%d %d %d \n",ALUREG[destino], BYPASS[destino], destino);
			if(destino == B){
				printf("dest e B \n");
				if(ALUREG[destino] == 1){
					printf("DEU RUIM B\n");
					FLAG = 1;
					estado = 25;
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
				estado = 25;
				break;
			}
			estado = 30;
		break;
		case 30:		
			//aumenta peso das arestas que levam a esse mesmo destino
			for(int aux=0; aux<V;aux++)
				if(m[aux][destino] != 0)
					m[aux][destino]++;
			estado = 31;
		break;
		case 31:				 
			//remove aresta usada
			m[origem][destino] = 0;
			//salva a origem no dataflow dessa aresta roteada em cada um dos PEs da rota
			ORIGEM_DF[origem][destino] = A;
			//printf("A = %d\n", A);

			w++;	
			estado = 24;	
		break;
		case 25:
			if(FLAG == 1){
				estado = 14;
				break;
			}
			estado =  16;
		}
	}
}




