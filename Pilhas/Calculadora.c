#include<stdio.h>
#include<stdlib.h>


int main(){
  char fila[40], pilha[40];
  int i = 0, c = getchar(), fim_pilha = 0, fim_fila = 0, inicio_fila = 0;

  while(c != '\n'){
    fila[i]=c;
    switch (c) {
      case '(':
        pilha[fim_pilha]=c;
        fim_pilha++;
      break;

      case ')':
        while(pilha[--fim_pilha]!='(')
          fila[fim_fila++]=pilha[fim_pilha];
      break;

      case '+':
      case '-':
      while(pilha[fim_pilha-1]!='(')
        fila[fim_fila++]=pilha[--fim_pilha];
      pilha[fim_pilha]=c;
      fim_pilha++;
      break;

      case '*':
      case '/':
      while(pilha[fim_pilha-1]!='+' && pilha[fim_pilha-1]!='-' && pilha[fim_pilha-1]!='(')
        fila[fim_fila++]=pilha[--fim_pilha];
      pilha[fim_pilha]=c;
      fim_pilha++;
      break;

      default: fila[fim_fila]=c; fim_fila++;
    }

    c=getchar();
    i++;
  }

  fila[fim_fila]='\0';
  printf("%s\n",fila);

  int conta[100],n1,n2;
  fim_pilha=0;

  for(i=0;fila[i]!='\0';i++){
    switch (fila[i]) {
      case '+':
        fim_pilha--;
        n1 = conta[fim_pilha-1];
        n2= conta[fim_pilha];
        conta[fim_pilha-1] =n1+n2;
      break;

      case '-':
        fim_pilha--;
        n1 = conta[fim_pilha-1];
        n2= conta[fim_pilha];
        conta[fim_pilha-1] =n1-n2;
      break;

      case '*':
        fim_pilha--;
        n1 = conta[fim_pilha-1];
        n2= conta[fim_pilha];
        conta[fim_pilha-1] =n1*n2;
      break;

      case '/':
        fim_pilha--;
        n1 = conta[fim_pilha-1];
        n2= conta[fim_pilha];
        conta[fim_pilha-1] =n1/n2;
      break;

      default: conta[fim_pilha++]=(int)(fila[i]-'0');
    }
  }
  printf("%d\n",conta[0]);

  return 0;
}
