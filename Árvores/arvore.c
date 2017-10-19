#include<stdio.h>
#include<stdlib.h>

typedef struct arv{
  char info;
  struct arv *esq;
  struct arv *dir;
  struct arv *prox;
}ARV;

ARV *arv_cria(char c, ARV *sae, ARV *sad){
  ARV *p;
  p=(ARV*)malloc(sizeof(ARV));
  p->info=c;
  p->esq=sae;
  p->dir=sad;
  return p;
}

int arv_vazia(ARV *p){
  return p==NULL;
}

ARV *arv_criavazia(){
  ARV *p=NULL;
    return p;
}

ARV *arv_destroi(ARV *a){
  if(!arv_vazia(a)){
    arv_destroi(a->esq);
    arv_destroi(a->dir);
    free(a);
  }
  return NULL;
}

void imprime_arvore_pre(ARV *p){
  if(p){
    printf("%c\n",p->info);
    imprime_arvore_pre(p->esq);
    imprime_arvore_pre(p->dir);
  }
}

void imprime_arvore_em(ARV *p){
  if(p){
    imprime_arvore_em(p->esq);
    printf("%c\n",p->info);
    imprime_arvore_em(p->dir);
  }
}

void imprime_arvore_pos(ARV *p){
  if(p){
    imprime_arvore_pos(p->esq);
    imprime_arvore_pos(p->dir);
    printf("%c\n",p->info);
  }
}

void imprime(ARV *p, int nivel){
     int i;
     if(p == NULL)
        return;
     imprime(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6c\n\n",p->info);
     imprime(p->esq,nivel+1);

}


int arv_consulta(ARV *a,char c){
  if(arv_vazia(a)){
    return 0;
  }else{
    return a->info==c||arv_consulta(a->esq,c)|| arv_consulta(a->dir,c);
  }
}


int main(){
  int opcao=-1,existe=0;
  ARV *a,*a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9,*a10,*a11,*a12;
  char procura;

  while(opcao!=0){
      printf("======MENU======\n");
      printf("0-Sair\n");
      printf("1-Cria arvore(pre-definida)\n");
      printf("2-Destroi a arvore\n");
      printf("3-Consulta elemento\n");
      printf("4-Imprime a arvore (Pré-ordem)\n");
      printf("5-Imprime a arvore (Em ordem)\n");
      printf("6-Imprime a arvore (Pós-ordem)\n");
      printf("7-Imprime arvore(largura)\n");
      printf("Opcao: ");
      scanf("%d",&opcao);

      switch(opcao){
        case 0:
        break;

        case 1:
          a1=arv_cria('b',arv_criavazia(),arv_criavazia());
          a2=arv_cria('c',arv_criavazia(),arv_criavazia());
          a3=arv_cria('a',arv_criavazia(),arv_criavazia());
          a4=arv_cria('*',a1,a2);
          a6=arv_cria('+',a3,a4);
          a7=arv_cria('a',arv_criavazia(),arv_criavazia());
          a8=arv_cria('b',arv_criavazia(),arv_criavazia());
          a9=arv_cria('+',a7,a8);
          a10=arv_cria('c',arv_criavazia(),arv_criavazia());
          a11=arv_cria('*',a9,a10);
          a=arv_cria('/',a6,a11);
        break;

        case 2:
          a=arv_destroi(a);
          if(a==NULL){
            printf("Arvore vazia!\n");
          }
        break;

        case 3:
        printf("Qual elemento que vc procura na arvore?\n");
        setbuf(stdin,NULL);
        scanf("%c",&procura);
        existe=arv_consulta(a,procura);
        if(existe==1){
          printf("Elemento existe!\n");
        }else{
          printf("Elemento nao existe!\n");
        }
        break;

        case 4:
        imprime_arvore_pre(a);
        break;

        case 5:
        imprime_arvore_em(a);
        break;

        case 6:
        imprime_arvore_pos( a);
        break;

        case 7:
        imprime(a,0);
        break;

        default:
        break;
      }
  }

  return 0;
}
