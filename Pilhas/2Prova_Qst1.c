#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void empilha(char *c){
	int n = strlen(c), topo = 0;
	char *pilha;
	pilha = malloc(n);
	for(int i = 0; c[i] != '\0'; i++){
		switch(c[i]){
			case ')':
				if(topo != 0 && pilha[topo-1] == '(')
					topo--;
				break;
			case '}':
				if(topo != 0 && pilha[topo-1] == '{')
					topo--;
					break;
			case ']':
				if(topo != 0 && pilha[topo-1] == '[')
					topo--;
					break;
			case '{':
			case '[':
			case '(':
				pilha[topo++] = c[i];
		}
	}
	if(topo == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main(){
  char nome[100];
  scanf("%s",nome);
  empilha(nome);
  return 0;
}
