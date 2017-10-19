#include <stdio.h>
#include <stdlib.h>

int quantidadeNos = 0;

typedef struct _no{
        int chave;
        int cont;

        struct _no *esq, *dir, *pai;
        }no;

no* auxPai = NULL;

void vaziaArvore(no *raiz){
    if (raiz == NULL){
             printf("   A arvore esta vazia\n\n");
             }
             else {
                  printf("   A arvore nao esta vazia\n\n");
                  }
    }

void insere (int x, no **p){

      if (*p==NULL){
                    *p=(no *)malloc(sizeof(no));
                    (*p)->chave=x;
                    (*p)->dir=NULL;
                    (*p)->esq=NULL;
                    (*p)->pai = auxPai;
                    (*p)->cont=0;
                    (*p)->cont++;
      }
      else{
            if (x<(*p)->chave){
                if((*p)->esq == NULL)
                    auxPai = *p;
                insere(x, &(*p)->esq);
            }
            if(x>(*p)->chave){
                if((*p)->dir == NULL)
                    auxPai = *p;
                insere(x, &(*p)->dir);
            }
            if(x == (*p)->chave){
                (*p)->cont++;
                return;
            }
      }
}

int contaNos(no *p){
    if(p != NULL){
         quantidadeNos ++;
         contaNos(p -> dir);
         contaNos(p -> esq);
    }
    return quantidadeNos;
}

no* busca(no *arvore, int x){
   if (arvore == NULL)
       return NULL;
   if (x == arvore->chave)
       return arvore;
   if (x < arvore->chave)
       return busca(arvore->esq, x);
   else
       return busca(arvore->dir, x);
}

void consultarValor(no* raiz){
    int num;
    no* aux;
    printf("Digite o numero procurado: ");
    scanf("%d", &num);

    aux = busca(raiz, num);
    if (aux == NULL)
       printf("Nao encontrado!\n");
    else{
       printf("Encontrado!\n");
       printf("O numero %d foi repetido %d vezes\n", num, aux->cont);
    }
}

void consultarDetalhes(no* raiz){
    int num;
    no* aux;
    printf("Digite o numero procurado: ");
    scanf("%d", &num);
    aux = busca(raiz, num);
    if (aux == NULL)
       printf("Nao encontrado!\n");
    else{
       printf("Encontrado!\n");
       printf("O numero %d foi repetido %d vezes.\n", num, aux->cont);
       if(aux->pai == NULL){
           printf("O No que contem o valor %d e a raiz da arvore.\n", num);
           if(aux->esq != NULL)
               printf("Valor contido no No filho a esquerda: %d\n", aux->esq->chave);
           if(aux->dir != NULL)
               printf("Valor contido no No filho a direito: %d\n", aux->dir->chave);
       }
       if((aux->esq == NULL)&&(aux->dir == NULL)&&(aux->pai != NULL)){
           printf("O No que contem o valor %d e uma folha da arvore.\n", num);
           printf("Valor contido no No pai: %d\n", aux->pai->chave);
       }
       if(((aux->esq != NULL)||(aux->dir != NULL))&&(aux->pai != NULL)){
           printf("O No que contem o valor %d e um no interno a arvore.\n", num);
           printf("Valor contido no No pai: %d\n", aux->pai->chave);
           if(aux->esq != NULL)
                printf("Valor contido no No filho a esquerda: %d\n", aux->esq->chave);
           if(aux->dir != NULL)
                printf("Valor contido no No filho a direito: %d\n", aux->dir->chave);
       }
    }
}

void imprime(no *p, int nivel){
     int i;
     if(p == NULL)
        return;
     imprime(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6d\n\n",p->chave);
     imprime(p->esq,nivel+1);

}

void consultaNivel(no *p){
     int i, nivel;
     if(p == NULL)
        return;
     imprime(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6d\n\n",p->chave);
     imprime(p->esq,nivel+1);
}

void preordem (no *arvore){
     if(arvore != NULL){
          printf("%d\n",arvore->chave);
          preordem(arvore->esq);
          preordem(arvore->dir);
     }
}

void emordem(no *arvore){
     if(arvore != NULL){
           emordem(arvore->esq);
           printf("%d\n",arvore->chave);
           emordem(arvore->dir);
     }
}

void posordem(no *arvore){
     if(arvore != NULL){
                 posordem(arvore->esq);
                 posordem(arvore->dir);
                 printf("%d\n",arvore->chave);
     }
}

void maiorValor(no* raiz){
    if((raiz->dir != NULL)&&(raiz->dir->chave > raiz->chave))
                 maiorValor(raiz->dir);
    else
                 printf("Maior Valor: %d\n", raiz->chave);
}

void menorValor(no* raiz){
    if((raiz->esq != NULL)&&(raiz->esq->chave < raiz->chave))
                 menorValor(raiz->esq);
    else
                 printf("Menor Valor: %d\n", raiz->chave);
}

//int quantNos(no* raiz){
//int cont;
  //  }

 int menu(){
           int op;
           printf("\n>>>>>>>>>>MENU<<<<<<<<<<\n\n");
           printf("1 - Consultar lista\n");
           printf("2 - Inserir valor\n");
           printf("3 - Imprimir pre ordem\n");
           printf("4 - Imprimir in-ordem\n");
           printf("5 - Imprimir pos ordem\n");
           printf("6 - Procurar um numero\n");
           printf("7 - Consulta detalhada\n");
           printf("8 - Consultar maior valor\n");
           printf("9 - Consultar menor valor\n");
           printf("10 - Quantidades de nos da arvore\n");
           printf("11 - Imprimir arvore\n");
           printf("12 - Sair\n\n>>>>>>>>>>MENU<<<<<<<<<<\n\n\n");
           printf("Digite sua opcao: ");
           scanf("%d", &op);
           return op;
           }


int main(){
    int n,a,b;
    no *raiz, *aux;
    raiz = NULL;
    int opcao;

    while(opcao!=12){
    system("clear");
    opcao = menu();
    switch(opcao){

                  case 1:
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       vaziaArvore(raiz);
                       printf(">>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       getchar();
                       break;
                  case 2:
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("Digite -1 para terminar\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       do{
                            printf("Digite um numero: ");
                            scanf("%d", &n);
                            if(n!=-1){
                            insere(n, &raiz);
                            }
                       }while (n!=-1);
                       system("clear");
                       printf("          (o)\n");
                       printf("       (o)(o)(o)\n");
                       printf("  ( ARVORE BINARIA )\n");
                       printf("     (o)(o)(o)(o)\n");
                       printf("         )  (\n");
                       printf("       __|  |__\n\n\n");
                       imprime(raiz,0);
                       getchar();
                       break;
                  case 3:
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Pre-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       preordem(raiz);
                       getchar();
                       break;
                  case 4:
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Em-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       emordem(raiz);
                       getchar();
                       break;
                  case 5:
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Pos-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       posordem(raiz);
                       getchar();
                       break;
                  case 6:
                       system("clear");
                       printf("\n\nDigite o numero procurado: ");
                       scanf("%d",&a);
                       aux = busca(raiz,a);
                       if (aux == NULL){
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("       Nao encontrado!\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       }
                       else{
                       system("clear");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("        Encontrado!\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       }
                       getchar();
                       break;
                  case 7:
                       system("clear");
                       consultarDetalhes(raiz);
                       getchar();
                       break;
                  case 8:
                       system("clear");
                       maiorValor(raiz);
                       getchar();
                       break;
                  case 9:
                       system("clear");
                       menorValor(raiz);
                       getchar();
                       break;
                  case 10:
                       system("clear");
                       b=contaNos(raiz);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("  A arvore possui %d nos!\n",b);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       getchar();
                       break;
                  case 11:
                       system("clear");
                       printf("ARVORE BINARIA\n");
                       imprime(raiz,0);
                       getchar();
                       break;
                  case 12:
                       exit(0);
                       break;

                  default :
                       system("clear");
                       printf("opcao nao existe! tente novamente");
                       getchar();
                       break;
                  }

                    }

    return 0;

}
