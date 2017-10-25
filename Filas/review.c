#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct fila {
  int vet[N];
  int ini, fim;
} Fila;

Fila *cria(){
  Fila *f = (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = 0;
  return f;
}

int incr(int i){
  return (i+1)%N;
}

void insere(Fila *f, int v){
  if(incr(f->fim) == f->ini){
    printf("Fila cheia!\n");
    exit(1);
  }else{
    f->vet[f->fim] = v;
    f->fim = incr(f->fim);
  }
}

int vazia(Fila *f){
  return(f->fim == f->ini);
}

int exclui(Fila *f){
  int v;
  if(vazia(f)){
    printf("Fila vazia\n");
  }else{
    v = f->vet[f->ini];
    f->ini = incr(f->ini);
  }
  return v;
}

void libera(Fila *f){
  free(f);
}

int main(){
  Fila *f;
  int opcao;
  int valor;
  int liberado;

  do {
    printf(">>>> MENU <<<<\n");
    printf("1 - Cria Fila\n");
    printf("2 - Insere na fila\n");
    printf("3 - Excluir da fila\n");
    printf("4 - Liberar Fila\n");
    scanf("%d",&opcao);

    switch (opcao) {
      case 0: exit(1);
        break;

      case 1:
        f = cria();
        break;

      case 2:
        printf("Posicao da fila %d\n",f->fim+1);
        scanf("%d",&valor);
        insere(f, valor);
        break;

      case 3: liberado = exclui(f);
        printf("%d\n",liberado);
        break;

      case 4: libera(f);
        break;
    }
  } while(opcao > 0);
  return 0;
}
