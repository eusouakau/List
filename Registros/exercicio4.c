#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct {
	char nome[50];
	char end[50];
	char aniver[50];
	char tel[50];
	char cel[50];
} pessoa;

void leitura (pessoa *p)  {
	printf("Nome: ");
	gets((*p).nome);
	printf("Endereco: ");
	gets((*p).end);
	printf("Aniversario: ");
	gets((*p).aniver);
	printf("Telefone: ");
	gets((*p).tel);
	printf("Celular: ");
	gets((*p).cel);
}

void imprime(pessoa p) {
	printf("Nome: %s\t Endereco: %s \t Aniversario: %s\n",p.nome, p.end, p.aniver);
	printf("Telefone: %s \tCelular:%s\n",p.tel, p.cel);
}

 main(int i) {
 	int num;
    pessoa pessoas[MAX];

 	for(i = 0; i < MAX; i++) leitura(&pessoas[i]);

 	do{
		printf("\nDigite um numero de 1 a %d:", MAX);
		scanf("%d", &num);
		imprime(pessoas[num-1]);
	} while(num);
	return 0;
}
