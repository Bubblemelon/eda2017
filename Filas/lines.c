/*
  Dicas para implementação vetor normal:
     ini == fim -> fila vazia
     fim == N -> fila cheia
     fila[fim++] = x <- inserção
     y = fila[ini++] <- remoção

  Dicas para implementação vetor circular:
     ini == fim -> fila vazia
     (fim+1 == ini) ou (fim+1 == N) e (ini == 0) -> fila cheia
     X = fila[ini++]; se(ini == N) -> ini = 0; -> remoção
     fila[fim++] = y; se(fim == N) -> fim = 0; -> inserção
     se(fim+1 == ini || fim+1 == N && ini == 0) -> transbordando!

Exercicios:
1-> Escreva um programa para simular o funcionamento de uma fila
num vetor de M posições de N inteiros, considerando N <= M = 6.
  Funções:
a) inserir um elemento da fila.
b) remover um elemento da fila.
c) imprimir a fila do inicio p/ o fim.
d) imprimir o comprimento da fila.
*/

#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct fila {
  int ini, fim;
  float vet[N];
} Fila;

Fila *cria(){
  Fila *f = (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = 0;
  for(int i = 0; i < N; i++)
  {
    f->vet[i] = 0.0;
  }
  return f;
}

int incr(int i){
  return (i+1)%N;
}

void insere(Fila *f, float v){
  if(incr(f->fim) == f->ini) {
    printf("Capacidade da fila estourou.\n");
    exit(1);
  }

  f->vet[f->fim] = v;
  f->fim = incr(f->fim);
}

int vazia(Fila *f){
  return (f->ini == f->fim);
}

float exclui(Fila *f){
  float v;
  if(vazia(f)) {
    printf("Fila vazia.\n");
    exit(1);
  }

  v = f->vet[f->ini];
  f->ini = incr(f->ini);
  return v;
}

void libera(Fila *f){
  free(f);
}

void printaFila(Fila *f){
  for(int i = 0; i < N; i++)
  {
    printf("%.1f\n" ,f->vet[i]);
  }
}

int main()
{
  Fila *f;
  float valor;
  int opcao;
  do {
    printf(">>>> MENU <<<<\n");
    printf("0 - SAIR\n");
    printf("1 - Criar Fila\n");
    printf("2 - Inserir\n");
    printf("3 - Excluir\n");
    printf("4 - Libera\n");
    printf("5 - Printa fila\n");
    scanf("%d",&opcao);
    system("clear");

    switch (opcao) {
      case 0:
        exit(1);
        break;

      case 1: cria();
        break;

      case 2:
        printf("%d\n",f->fim);
        scanf("%f",&valor);
        insere(f, valor);
        break;

      case 3:
        exclui(f)
        break;

      case 4: libera(f);
        break;

      case 5: printaFila(f);
        break;
    }
  } while(opcao > 0);
}
