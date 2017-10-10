/*
  Filipe Dias - 160006163
  Gabriel Albino - 160028361
  André Bargas - 120110237
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct{
	int x;
	int y;
}pos;

#define MAX 100 // capacidade de armazenamento da pilha e da fila
typedef int titem; // tipo dos itens armazenados na pilha e na fila
#define N 7// tamanho da matriz que representa o labirinto
#define LIVRE 0 // marca de posicao livre no labirinto
#define PAREDE 32767// marca de posicao com parede no labirinto
void cria(int L[N][N]) { // funcao para criacao de um labirinto
	int i,j;
	for(i = 0; i < N; i++){
		for(j=0; j< N; j++){
			L[i][j] = LIVRE;
		}
	}
	for(i = 0; i < N; i++){
		L[0][i] = PAREDE;
	}
	for(i = 0; i < N; i++){
		L[N-1][i] = PAREDE;
	}
	for(i = 2; i < N; i++){
		L[i][0] = PAREDE;
	}
	for(i = 0; i < 5; i++){
		L[i][N-1] = PAREDE;
	}
	for(i = 1; i < 4; i++){
		L[i][2] = PAREDE;
	}
	for(i = 2; i < 5; i++){
		L[i][4] = PAREDE;
	}
	L[5][2] = PAREDE;
}/* fim­cria */

void exibe(int L[N][N]) { // funcao para exibicao de um labirinto
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++)
			switch( L[i][j] ) {
				case LIVRE :
					putchar(' ');
					putchar(' ');
					break;
				case PAREDE:
					putchar('#');
					putchar(' ');
					break;
				case PAREDE-1:
					putchar('x');
					putchar(' ');
					break;
				default:
					putchar(126);
					putchar(' ');
			}
			printf("\n");
	}
}
int adcionaFila(pos n, pos* fila, int *inicio, int fim){
	if(fim == MAX){
		fim = 0;
	}
	if(fim+1 == *inicio || (fim+1 == MAX && *inicio == 0)){
		*inicio+=1;
		if(*inicio == MAX){
			*inicio = 0;
		}
	}
	fila[fim++] = n;
	return fim;
}//*

pos removeFila(pos* fila, int *inicio){
	pos x;
	if(*inicio == MAX){
		*inicio = 0;
	}
	x = fila[*inicio];
	*inicio += 1;
	return x;
}

//Adicione aqui o codigo da função anota() ­ exercício 2
void anota(int L[N][N]){
	pos fila[MAX];
	int inicio=0, fim=0;
	int c;

	L[1][1] = 1;
	pos temp;
	pos vizinho;

	temp.x = 1;
	temp.y = 1;
	fim = adcionaFila(temp, fila, &inicio, fim);
	while(inicio!=fim){
		temp = removeFila(fila, &inicio);
		c = L[temp.x][temp.y] + 1;
		if(L[temp.x+1][temp.y] == 0){
			vizinho.x = temp.x+1;
			vizinho.y = temp.y;
			L[vizinho.x][vizinho.y] = c;
			fim = adcionaFila(vizinho, fila, &inicio, fim);
		}
		if(L[temp.x][temp.y+1] == 0){
			vizinho.x = temp.x;
			vizinho.y = temp.y+1;
			L[vizinho.x][vizinho.y] = c;
			fim = adcionaFila(vizinho, fila, &inicio, fim);
		}
		if(L[temp.x-1][temp.y] == 0){
			vizinho.x = temp.x-1;
			vizinho.y = temp.y;
			L[vizinho.x][vizinho.y] = c;
			fim = adcionaFila(vizinho, fila, &inicio, fim);
		}
		if(L[temp.x][temp.y-1] == 0){
			vizinho.x = temp.x;
			vizinho.y = temp.y-1;
			L[vizinho.x][vizinho.y] = c;
			fim = adcionaFila(vizinho, fila, &inicio, fim);
		}
	}
	L[1][0] = 0;
	L[5][6] = PAREDE-1;
}
//Adicione aqui o codigo da função extrai() ­ exercício 3
void extrai(int L[N][N]){
	pos pilha[MAX];
	int topo = 0;
	if(L[N-2][N-2] == 0){
		printf("Não há saída\n");
		return;
	}
	pilha[topo].x = N-2;
	pilha[topo++].y = N-2;
	pos temp;
	pos vizinho;
	while(L[pilha[topo-1].x][pilha[topo-1].y] != 0){
		temp = pilha[topo-1];
		if(L[temp.x+1][temp.y] == L[temp.x][temp.y]-1){
			vizinho.x = temp.x+1;
			vizinho.y = temp.y;
			pilha[topo++] = vizinho;
		}
		if(L[temp.x][temp.y+1] == L[temp.x][temp.y]-1){
			vizinho.x = temp.x;
			vizinho.y = temp.y+1;
			pilha[topo++] = vizinho;
		}
		if(L[temp.x-1][temp.y] == L[temp.x][temp.y]-1){
			vizinho.x = temp.x-1;
			vizinho.y = temp.y;
			pilha[topo++] = vizinho;
		}
		if(L[temp.x][temp.y-1] == L[temp.x][temp.y]-1){
			vizinho.x = temp.x;
			vizinho.y = temp.y-1;
			pilha[topo++] = vizinho;
		}
	}
	while(topo != 0){
		temp = pilha[--topo];
		L[temp.x][temp.y] = PAREDE-1;
	}
	exibe(L);
}

int main(void) { // Função principal
	int L[N][N];
	char r;
	srand(time(NULL));
	do{
		cria(L);
		anota(L); // retire o comentario na versão final
		extrai(L); // retire o comentario na versão final
		printf("Continua? (s/n) ");
		scanf("%c%*c",&r);
	}while( toupper(r)!='N' );
	return 0;
}
