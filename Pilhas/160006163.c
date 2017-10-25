#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int empilha(int N){
  int pilha[N], topo;
  int i, peso, massa = 0;

  topo = 0;
  for(i = 0; i < N; i++){
    scanf("%d",&peso);
    if(topo == 0){
      pilha[topo] = peso;
      massa += pilha[topo];
      topo++;
    }else{
      if(peso <= pilha[topo-1]){
        pilha[topo] = peso;
        massa += pilha[topo];
        topo++;
      }
    }
  }

  return massa;
}

int main(){
  int N;
  scanf("%d",&N);
  int pilha;
  pilha = empilha(N);
  printf("MASSA EMPILHADA: %d kg\n", pilha);
  return 0;
}
