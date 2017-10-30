#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nro[10];
}senha;

int adcionarNaFila(senha* fila, senha elemento, int inicio, int final, int tamanho){
  if(final == tamanho){
    final = 0;
  }
  fila[final++] = elemento;
  return final;
}

int adcionarNoInicioDaFila(senha* fila, senha elemento, int inicio, int final, int tamanho){
  int f = final;
  while(fila[inicio].nro[0] == 'P'){
    inicio++;
  }
  while(f != inicio){
    fila[f] = fila[f-1];
    f--;
    if(f == -1){
      f == tamanho-1;
    }
  }
  fila[inicio++] = elemento;
  return final+1;
}

senha retirarDaFila(senha* fila, int* inicio, int final, int tamanho){
  senha elemento;
  if(*inicio == tamanho){
    *inicio = 0;
  }
  elemento = fila[*inicio];
  *inicio = *inicio + 1;
  return elemento;
}

void imprimeElemento(senha elemento){
  printf("%s ", elemento.nro);
}

void imprimeFila(senha* fila, int inicio, int final, int tamanho){
  printf("\n");
  while(inicio != final){
    imprimeElemento (fila[inicio++]);
    if(inicio == tamanho){
      inicio == 0;
    }
  }
  printf("\n");
}

int main(){
  senha temp;
  int nroComandos, inicio = 0, fim = 0;
  senha* fila;
  scanf("%d", &nroComandos);
  fila = malloc(nroComandos*sizeof(senha));
  for(int i = 0; i < nroComandos;i++){
    printf("Insira a senha: ");
    scanf("%s",temp.nro);
    if(temp.nro[0] == 'a'){
        retirarDaFila(fila, &inicio, fim, nroComandos);
        //imprimeFila(fila, inicio, fim,nroComandos);
    }
    else{
      if(temp.nro[0] == 'P'){
          //printf("adcionando o elemento no inicio.\nFim anterior: %d", fim);
          fim = adcionarNoInicioDaFila(fila, temp, inicio, fim, nroComandos);
          //printf("fim atual: %d\n", fim);
            //imprimeFila(fila, inicio, fim,nroComandos);
      }
      else if(temp.nro[0] == 'N'){
          //printf("adcionando o elemento no final da fila.\nFim anterior: %d", fim);
          fim = adcionarNaFila(fila, temp, inicio, fim, nroComandos);
          //printf("fim atual: %d\n", fim);
            //imprimeFila(fila, inicio, fim,nroComandos);
      }
    }
  }
  if(inicio == fim){
    printf("NENHUM CLIENTE\n");
  }
  else
    imprimeFila(fila, inicio, fim,nroComandos);
}
