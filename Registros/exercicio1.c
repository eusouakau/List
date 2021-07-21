#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct {
	char nome[50];
	char end[50];
	char aniver[20];
	char tel[15];
	char cel[15];
} pessoa;

pessoa vet[MAX];

void imprime(int i) {
	printf("Nome: %s\t Endereco: %s \t Aniversario: %s\n",vet[i].nome, vet[i].end, vet[i].aniver);
	printf("Celular: %s \tTelefone:%s\n",vet[i].cel, vet[i].tel);
}

 main() {
 	int i, num;
 	
 	for(i = 0; i < MAX; i++) {
 		printf("Nome:");
 		gets(vet[i].nome);
 		printf("Endereco:");
 		gets(vet[i].end); 
 		printf("Aniersario:");
 		gets(vet[i].aniver);
 		printf("Telefone:");
 		gets(vet[i].tel);
 		printf("Celular:");
 		gets(vet[i].cel);
	 }
 	
 	do{
		printf("\nDigite um numero de 1 a %d:", MAX);
		scanf("%d", &num);
		imprime(num-1);
	} while(num);
	return 0;
}
