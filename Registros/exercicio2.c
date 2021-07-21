#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2

typedef struct{
	char nome[150];
	char tel[15];
	int idade;
	char contato[150];
} aluno;

aluno a[MAX];

void leitura(int i){
	printf("Digite o nome do aluno: ");	
	gets(a[i].nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&a[i].idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets(a[i].contato); 
	printf("Digite o Telefone do Contato: ");
	gets(a[i].tel); 
}

void imprime(int i){
            printf("%s\n%s\n%d\n%s\n",a[i].nome, a[i].tel, a[i].idade, a[i].contato);
}

int main(int argc, char *argv[]) {
	int i,num;
	for(i=0;i<MAX;i++) leitura(i);
	
	do{
		printf("\nDigite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime( num-1);
	} while(num);
	return 0;
}
