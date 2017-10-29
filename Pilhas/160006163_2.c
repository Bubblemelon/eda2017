#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int empilha(int N){
  int pilha[N];
  int topo = 0;
  int peso, massa_total = 0;

  for(int i = 0; i < N; i++){
    pilha[i] = 0;
  }

  for(int i = 0; i < N; i++){
    scanf("%d",&peso);
    if(i == 0){
      pilha[topo++] = peso;
    } else{
      if(peso <= pilha[topo-1]){
          pilha[topo++] = peso;
      }
    }
  }

  while(topo >= 0){
    massa_total += pilha[topo];
    topo--;
  }

  return massa_total;
}

int main(){
    int N, massa;
    scanf("%d",&N);
    massa = empilha(N);
    printf("MASSA EMPILHADA: %d kg\n",massa);
    return 0;
}
