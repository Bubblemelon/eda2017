#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 30

typedef struct{
    int tikets;
    char nome[TAM_NOME];
}infoPessoas;

int adcionaPessoaFila(infoPessoas* fila, infoPessoas proxima, int tamanhoFila, int fim, int inicio){
    if(fim == tamanhoFila)
        fim = -1;
    fila[fim++] = proxima;
    return fim;
}

int recebeInfoPessoas(infoPessoas* fila,int qtd){
    int nro = 0;
    for(; nro<qtd; nro++){
        scanf("%s %d",fila[nro].nome, &fila[nro].tikets);
    }
    return nro;
}

int main(){
    int cestas, pessoas, inicio = 0, fim = 0;
    infoPessoas* fila, proxima;
    scanf("%d %d", &cestas,&pessoas);
    fila = malloc(pessoas*sizeof(fila));
    fim = recebeInfoPessoas(fila, pessoas);
    while(cestas && inicio != fim){

        proxima = fila[inicio++];

        if(inicio == pessoas)
            inicio = 0;

        proxima.tikets -= 1;
        if(proxima.tikets > 0){
            fim = adcionaPessoaFila(fila, proxima, pessoas, inicio, fim);
        }
        cestas--;
    }
    if(cestas == 0){
        printf("%s RECEBEU A ULTIMA CESTA\n", proxima.nome);
    }
    else{
        printf("AS CESTAS ATENDERAM A TODOS OS CIDADAOS\n");
    }
}
