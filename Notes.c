15/08
---------------------------------------------------------------
* Alocação estática:
  exemplo:
---------------------------------------------------------------
ex. 1.1
#include <stdio.h>
int power (int px) {
  int py;
  py = px + px;
  return (py);
} /* fim-power */

int main () {
  int x = 2;                                    <<<<< Exemplo de alocação estática
  int y;
  y = power(x);

} /* fim-main */
---------------------------------------------------------------

* Alocação NÃO É INFINITA. Por isso, deve-se trabalhar com
alocação dinâmina de memória: malloc, calloc, free.

PS: A implementação acima usa passagem de parâmetro por valor:
 Há uma troca de valores entre a função e a main.
 Y recebe o valor da função power(x) e vice versa.

Para passar por referência, deve-se:
---------------------------------------------------------------
ex. 1.2
#include<stdio.h>
void power(int *py, int *px){
  *py = *px + *px;                              PS: int *y -> cria na memória um endereço de y
                                                              que conterá um tipo int
} /* fim-power */                               PS.2: int x -> cria na memória um tipo int;

void main(){
  int y = 2, x = 2;
  power(&y,&x);                                 PS.3: Acessa-se o endereço de 'y' e de 'x'

  printf("%d = %d\n",x,y);
}
---------------------------------------------------------------
Vetores -> MANIPULAÇÃO
ex 2.1
void lerNome_Aluno(char *nome){
  int i = 1, c;                                 PS: int C / c = getchar()? WTF???
  char *aux;                                    -> getchar() retorna um inteiro
  aux = nome;
  setbuf(stdin,NULL);

  while((c = getchar())!= '\n')
  {                                             PS.2: FOCO NESSA MANIPULAÇÃO DE SE PEGAR UM CARACTER
    *aux = c;
    aux = nome + i;
    i++;
  }
  *aux = '\0';
}

---------------------------------------------------------------
FOCO!!: Vetores, matrizes, variáveis multidimensionais...
        Só passam valores por referência!!!!
---------------------------------------------------------------
ex. 2.2
#include<stdio.h>

void leia_string(char *s) {
   int i, c;                                    PS: como s[] no exemplo 2.1 recebe uma posição na memória,
   c = getchar();                               é possivel usar um ponteiro *s para modificar a mesma posição
   if (c =='\n') {
       c = getchar();                           PS.2: Não se poe o tamanho do vetor como parâmentro na função void
   } /* fim-if */
   i=0;
   while (c!='\n') {
       s[i] = c;
       c = getchar();
       i++;                                      PS.3: FOCO NESSA MANIPULAÇÃO DE SE PEGAR UM CARACTER
   } /* fim-while */
   s[i] = '\0';
} /* fim-leia_string */

void main(){
  char nome[30];       <<<<<<<< ALOCAÇÃO ESTÁTICA
  leia_string(nome);
  printf("%s\n",nome);
} /* fim-da-main */

---------------------------------------------------------------
ex. 2.3
#include<stdio.h>

void leia_string(char *s) {
   int c;
   c = getchar();
   if (c =='\n') {
       c = getchar();
   } /* fim-if */
   i=0;
   while (c!='\n') {
       /*s[i] = c;*/ << troca-se por:
       (*s) = c;
       c = getchar();                           PS.1: Nesse caso, some-se o i, porque está usando o próprio
       s++;                                     endereço para a modificação.
   } /* fim-while */
   /*s[i] = '\0';*/                             PS.2: CUIDADO COM O SALTO s++! Como s é do tipo char *s, usa-se
} /* fim-leia_string */                         só um byte = 4 bits.
                                                  Caso fosse um tipo int *s, pulariam-se 4 bytes = 32 bits

void main(){
  char nome[30];       <<<<<<<< ALOCAÇÃO ESTÁTICA
  leia_string(nome);
  printf("%s\n",nome);
} /* fim-da-main */
---------------------------------------------------------------
ex 3.1
#include<stdio.h>
void leia_string(char *s) {
   int c;
   c = getchar();
   if (c =='\n') {
       c = getchar();
   } /* fim-if */
   i=0;
   while (c!='\n') {
       /*s[i] = c;*/ << troca-se por:
       (*s) = c;
       c = getchar();
       s++;
   } /* fim-while */
   /*s[i] = '\0';*/
} /* fim-leia_string */

void main(){
  char *nome;
                                                <<<< O QUE ESTÁ ERRADO NO CÓDIGO AO LADO?
  leia_string(nome);
  printf("%s\n",nome);
} /* fim-da-main */
---------------------------------------------------------------
ex. 3.2
#include<stdio.h>
void leia_string(char *s) {
   int c;
   c = getchar();
   if (c == '\n') {
       c = getchar();
   } /* fim-if */
   i=0;
   while (c!='\n') {
       /*s[i] = c;*/ << troca-se por:
       (*s) = c;
       c = getchar();
       s++;
   } /* fim-while */
   s[i] = '\0';
} /* fim-leia_string */

void main(){
  char *nome;
  nome = (char *)malloc(30*sizeof(char));

  leia_string(nome);
  printf("%s\n",nome);
} /* fim-da-main*/
---------------------------------------------------------------
PS.: É possível alocar memória dentro de uma função?
                  (DESTINO e não na ORIGEM)
---------------------------------------------------------------
Tipos de Dados ->
  . char: 8 bits
  . int: 32 bits
  . float: 64 bits
  . short:                                      <<<<<< ACHAR INTERVALOS!
  . unsigned:
  . double: 64 bits
---------------------------------------------------------------
Manipulando vetores como estrutura de Dados -> Aula 18/pag.3
fat =  ∑(quantidade[i] * preco[i])


---------------------------------------------------------------

17/08
---------------------------------------------------------------
Ordenação de Vetores
ex 1.1: ordenar de acordo com a nota maior:
-> ordenação: uma comparação entre 2 valores .V1 & .V2
* 3 valores: ordem crescente:  .V1 & .V2 & .V3
#include<stdio.h>
int main()
{
  int v1, v2, v3;
  scanf("%d %d %d",&v1,&v2,&v3);
  if (/* condition */) {
    /* code */                                  <<< Para até 4 valores, não é necessário o uso de vetores
  }                                                 Basta apenas usar várias condition`s.
  printf("%d %d %d\n",&v1,&v2,&v3);
}

---------------------------------------------------------------
Bubble Sort -> Algoritmo de ordenação de vetores:
ex. 1.1.2:
#include<stdio.h>

void ordena_nota()
{
  int i = 0;
  while(i < 6)
  {
    if(A[i] > A[i+1])
    {
      int aux = A[i];                           <<<<< Exemplo feito para ordenação
      A[i] = A[i+1];                            <<<<< A função joga o maior elemento para o topo da pilha
      A[i+1] = aux;
    }
    i++;
  }
}
---------------------------------------------------------------
OLHAR DB1.c
---------------------------------------------------------------
22/08
---------------------------------------------------------------
Ordenação de Vetores/Pesquisa em Vetores

Operações típicas em estruturas de Dados:
1. Consulta(leitura)/pesquisa,
2. Atualizacao(escrita),
3. Insercao
4. Exclusao
---------------------------------------------------------------
Parametro de consulta (K)
Pesquisa Sequencial -> Algoritmo de pesquisa em vetores
#include<stdio.h>
int achei = -1;

int main()
{
  int i = 0;
  while(i < n)
  {
    if(k == v[i]){                              <<<<< Pesquisa muito lenta :(
      achei = i;
      i = n;
    }
    i++;
  }
}
---------------------------------------------------------------
Pesquisa Binária -> Pressupõe ordenação
#include<stdio.h>
void pesquisa_binaria(int *vetor, int k){
  int res, ini, fim, meio;
  res = -1;
  ini = 0;
  fim = 6;
  do {
    meio = (ini + fim)/2;
    if(k < vetor[meio]){
      fim = meio - 1;
    }
    else{
      ini = meio + 1;
    }
  } while((ini <= fim) && (k != vetor[meio]));
  if(k == vetor[meio]){
    res = meio;
  }
  printf("ACHOU: %d",res);
}
---------------------------------------------------------------
OLHAR DB2.c
---------------------------------------------------------------
24/08
---------------------------------------------------------------
Manipulação de Vetores
Parte 2 ->
  Operações típicas:
  * inserção
  * remoção
  * alteração
---------------------------------------------------------------
OLHAR CadastroAluno.c -> CODIGOS
---------------------------------------------------------------

OBS: Ponteiros de função
Aula Fabrício                                   <<<<< "DESCONSIDERAR"

exemplo: int (*fp)(int, int)                    <<<<< OLHAR SLIDES
---------------------------------------------------------------
05/09
---------------------------------------------------------------
TREINAR Inserção Ordenada -> SHIFT
---------------------------------------------------------------
Exclusão
Para excluir:

#include<stdio.h>
typedef struct{
  int matricula;
  char nome[TAM_NOME];
  int STATUS;                                    <<<<< Para excluir, basta colocar o STATUS == 0 e printar os STATUS == 1
} formulario;
---------------------------------------------------------------
Listas Encadeadas
Ações:
  * Inclusão
  * Exclusão
  * Alteração
  * Consulta

#include<stdio.h>

struct elemento{
  int info;
  struct elemento *prox;                        <<<<< Uma Lista Encadeada é auto referenciada
};

l -> [INFO|•]-->[INFO|•]-->etc-->[INFO|•]--> NULL
l = apontador para o endereço de início da lista encadeada
                        ou
{    l aponta para um nó ou l aponta para nulo (NULL)     }

[[[[Uma Lista Encadeada é auto referenciada]]]]

struct elemento *lst_cria(void){

  return(NULL);
}

struct elemento *lst_insere(struct elemento *l, int valor){
  struct elemento *novo = (struct elemento*)malloc(sizeof(struct elemento));
  novo -> info = valor;
  novo -> prox = l;
    return (novo);
} /*Fim lst_insere */

int main(void){
  struct elemento *l;
  l = lst_cria();
  l = lst_insere(l,23);
  l = lst_insere(l,45);
  l = lst_insere(l,58);
  printf("kbo!\n");
  return 0;
}

VER ListaEncadeada.c
---------------------------------------------------------------
PROCESSO: É um programa em execução
---------------------------------------------------------------

2º Modulo: Filas

  Uma fila é uma estrutura de dados que admite inserção de novos elementos
e remoção de elementos antigos, de acordo com a política de FIFO
FIFO -> FIRST IN .FIRST OUT

a) a implementação de fila simples em vetor:

  0      ini         fim         n-1
[   |   |***|***|***|***|   |   |   ]

DICAS:
  * Se ini == fim -> fila vazia
  * Se fim == N -> fila cheia
  * P/ inserir -> fila[fim++] = X;
  * P/ remover -> y = fila[ini++];

b) Implementação de fila circular em vetor
  Possibilidades:

  0      ini         fim             n-1
[   |   |***|***|***|***|   |   |   |   ]

  0      fim            ini         n-1
[***|***|***|   |   |   |***|***|***|***]

Dicas:
  * Se (ini == fim) -> fila vazia
  * Se (fim+1 == ini) ou (fim+1 == N) e (ini == 0) -> fila cheia
  * P/ remover: X = fila[ini++];
               se(ini == N) -> ini = 0;
  * P/ inserir: fila[fim++] = y;
               se(fim == N) -> fim = 0;
  * P/ checar se a fila está transbordando:
    se(fim+1 == ini || fim+1 == N && ini == 0) -> transbordando!

Exercicios:
1-> Escreva um programa para simular o funcionamento de uma fila
num vetor de M posições de N inteiros, considerando N <= M = 6.
  Funções:
a) inserir um elemento da fila.
b) remover um elemento da fila.
c) imprimir a fila do inicio p/ o fim.
d) imprimir o comprimento da fila.

2-> Escreva um programa p/ simular o funcionamento
de uma fila de N inteiros num vetor de M posições tal que N > M = 6.
Considerar as mesmas funções do exercício anterior.

Exemplo:
  Menor distância entra cidades


-- - - - - -  - - - - - - - - > 0
|                               ^
1 < - - - - - - - - - - - - - - | - - - - 5
^                               |
|                               |
|                               |
|                               |
|                               |
2 - - - - - - - - - - - - - - > 4
^                               ^
|                               |
|-- - -- -- - - - - 3 - - - - -


    0  1  2  3  4  5
0  [0][0][0][0][0][0]
1  [1][0][0][0][0][0]
2  [0][1][0][0][1][0]
3  [0][0][1][0][1][0]
4  [1][0][0][0][0][0]
5  [0][1][0][0][0][0]


int *distancias(int A[][6], int c){
  int *d, j;
  int fila[6], ini, fim;
  int i, di;

  d = malloc(6 * sizeof(int));
  for(j = 0; j < 6; j++) d[j] = 6;
  d[c] = 0;

  ini = 0;
  fim = 0;
  fila[fim++] = c;

  while(ini != fim){
    i = fila[ini++];
    di = d[i];
    for(j = 0; j < 6; j++)
    {
      if(A[i][i] == 1 && d[j] >= 6)
      {
        d[j] = di + 1;
        fila[fim++] = j;
      }
    }
  }
  return(d);
}
---------------------------------------------------------------

Pilhas -> estruturas de dados que admitem inserção e remoção
de elementos, segundo a política LIFO ("Last in First Out")

implementação em um vetor:

n - 1[  ]         Dicas:
.    [  ]     * Se topo == 0 -> pilha vazia
.    [  ]     * Se topo == N -> pilha cheia
.    [  ]     * p/ inserir/empilhar ->
4    [  ]         pilha[topo++] = x;
3    [  ]             (ou to_push ou push)
2    [  ]<- topo
1    [**]     * p/ remover/desempilhar ->
0    [**]        y = pilha[--topo]
    .pilha            (ou to_pop ou pop)

int pilha[N]


Exemplo de uso:
a) Construindo uma função p/ checar se uma sequência de colchetes
e parênteses está bem formada:

int bemFormada(char *s)
{
  char *pilha; int topo;
  int n, i;
  n = strlen(s);

  pilha = malloc(n*sizeof(char));
  topo = 0;
  for(i = 0; s[i]!='\0'; i++)
  {
    switch(s[i]){
      case ')':
          if(topo != 0 && pilha[topo-1] == '(')
            topo--;
          else
            return 0;
          break;

      case ']':
          if(topo != 0 && pilha[topo-1] == '[')
            topo--;
          else
            return 0;
          break;

      default:
          pilha[topo++] = s[i];
    }
  }
}

b) Implementar uma função que consiga ler uma função
em notação infixa p/ notação polonesa (posfixa):

------------------------------------------------------------------------------
| infixa                              |           POLONESA (POSFIXA)          |
------------------------------------------------------------------------------
| (A+B*C)                             |                                       |
------------------------------------------------------------------------------
| (A*(B+C)/D-E)                       |                                       |
------------------------------------------------------------------------------
| (A+B*(C-D *(E -F)-G*H)-I*3)         |                                       |
------------------------------------------------------------------------------
| (A+B*C/D*E-F)                       |                                       |
------------------------------------------------------------------------------
| (A + (B - (C + (D - (E + F)))))     |                                       |
------------------------------------------------------------------------------
|(A * (B + (C * (D - (E * (F + G))))))|                                       |
------------------------------------------------------------------------------

* Ler apostila!

Procurar: percepção de conceitos de Pilhas e Filas
