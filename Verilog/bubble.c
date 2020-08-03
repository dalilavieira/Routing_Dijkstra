#include <stdio.h> 
#include <limits.h> 

//tem 10 estados
void bubble(int *v){
	int aux, aux2;
	int estado = 0;
	int i,j, vi, vj;

	while(1){
		//printf("%d %d \n", i, j);
		if(i == 7-1 && j == 7-1)
			break;

		switch (estado){
			case 0:
				i = 0;
				j = 0;
				estado = 8;
			break;
			case 8:
				if(i < 7)
					estado = 9;
				//else   fim
			break;
			case 9:
				vi = v[i];
				estado = 10;
			break;
			case 10:
				vj = v[j];
				estado = 1;
			break;
			case 1:
				if(vj > vi) //lê 2 memorias
					estado = 5;
				else
					estado = 3;
			break;
			case 5:
				aux = v[i];
				estado = 6;
			break;
			case 6:
				aux2 = v[j]; //escreve na memoria
				estado = 7;
			case 7:
				v[i] = aux2;
				estado = 2;
			break;
			case 2:
				v[j] = aux; //escreve em memoria
				estado = 3;
			break;
			case 3:
				j = j + 1;
				estado = 4;
			break;
			case 4:
				if(j == 7-1){
					j = 0;
					i = i + 1;
				}
				estado = 8;		
			break;
		}
	}
}

int main(){
	int v[] = {2,4,8,1,2,6,3};
	
	bubble(v);

	for (int j=0; j<7; j++)
		printf("%d\n", v[j]);
}
