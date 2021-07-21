#include <stdio.h>
#include <stdlib.h>

#define MAX 5


typedef struct{
	char nome[50];
	char tel[15];
	int idade;
	char contato[10];
} aluno;


 void leitura (aluno *a)  {
	printf("Digite o nome do aluno: ");
	gets((*a).nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&(*a).idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets((*a).contato);
	printf("Digite o Telefone do Contato: ");
	gets((*a).tel);
}

void imprime(aluno a){
	printf("Nome: %s\n Idade: %d anos\n",a.nome, a.idade);
	printf("Contato: %s \nTelefone:%s\n",a.contato, a.tel);
}

main(int i) {
    int num;
    aluno alunos[MAX];
	for(i=0;i<MAX;i++) leitura(&alunos[i]);
	do{
		printf("\nDigite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime( alunos[num-1]);
	} while(num);
	return 0;
}
