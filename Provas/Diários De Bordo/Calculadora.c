#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct no{
 double valor;
 struct no *prox;
 struct no *ant;
}no;

typedef struct cabecarioPilha{
  struct no *ini;
  struct no * topo;
}cab;

cab* inicCab(){
  struct cabecarioPilha * c =(cab*)malloc(sizeof(cab));
  c->ini =(no*)malloc(sizeof(no)) ;
  c->topo =(no*)malloc(sizeof(no)) ;
  c->ini = NULL;
  c->topo = NULL;
  return c;
}

void push(cab *c, double i){
  no * novo = malloc(sizeof(no));
  (novo->ant) = (no*)malloc(sizeof(no));
  (novo->prox) = (no*)malloc(sizeof(no));
  novo->valor = i;
  if(c->ini == NULL){//aponta o começo e o topo da pilha, indicados no cabecario para o primeiro elemento a ser inserido na pilha
    novo->ant = NULL;
    novo->prox = NULL;
    c->ini = novo;
    c->topo= novo;
    return;
  }
  else{
    c->topo->prox = novo;//aponta topo para novo elemento
    novo->ant = c->topo;//aponta anterio do novo elemento para topo
    c->topo = novo;//topo recebe o novo elemento
  }
}

no pop(cab *c){
  no *retirado = (no*)malloc(sizeof(no));
  retirado = c->topo;
  if(c->topo == c->ini){
    c->topo = c->topo->ant;
    c->ini = c->ini->ant;
  }
  else{
    c->topo = c->topo->ant;
    //free(c->topo->prox);
    c->topo->prox = NULL;
  }

  return *retirado;
}

int calculaPSF(cab *c, char s[MAX]){
  int n, i=0;
  double aux = 0;
  no a, b;
  char k;
  n = strlen(s);
  for(i=0; i<n; i++){
    k = s[i];
    switch(k){

      case '+':
        a=(pop(c));
        b=(pop(c));
        aux = (a.valor+b.valor);
        push(c, aux);
        break;
      case '-':
        a=(pop(c));
        b=(pop(c));
        aux = (a.valor- b.valor);
        push(c, aux);
        break;
      case '*':
        a=(pop(c));
        b=(pop(c));
        aux = (a.valor*b.valor);
        push(c, aux);
        break;
      case '/':
        a=(pop(c));
        b=(pop(c));
        aux = (b.valor/a.valor);
        push(c, aux);
        break;
      default:
        aux = (s[i] - 48);// pode ser feito com s[i] - 47 tambem ao invés do atof
        push(c, aux);
        break;
    }
  }
  return aux;
}


int main(){

char string[MAX];
struct cabecarioPilha *c;
double resultado;

c = inicCab(); //inicializando cabecalho;
scanf("%s", string);
resultado = calculaPSF(c, string);
printf("resultado : %.2lf \n", resultado);
return 0;
}
