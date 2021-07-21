#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1
typedef struct{
	char nome[150];
	char telefone[15];
	int idade;
	char contato[150];
} aluno;

void leitura(aluno *a){
	printf("Digite o nome do aluno: ");
	gets((*a).nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&(*a).idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets((*a).contato);
	printf("Digite o Telefone do Contato: ");
	gets(a->telefone);
}
void imprime(aluno a){
	printf("Nome: %s\t Idade: %d anos\n",a.nome,a.idade);
	printf("Contato: %s \tTelefone:%s\n",a.contato,a.telefone);
}

int main(int argc, char *argv[]) {
	aluno* alunos[MAX];
	int i,num;
    printf("aluno[] ocupa %d de bytes\n", sizeof(alunos[0]));
    printf("aluno ocupa %d de bytes\n", sizeof(aluno));
    printf("i: %d\n", sizeof(i));
    printf("num: %d\n", sizeof(num));
    printf("soma: %d\n", sizeof(aluno) + sizeof(alunos[0]) + sizeof(i) + sizeof(num));

	for(i=0;i<MAX;i++)alunos[i]=0;


	for(i=0;i<MAX;i++) {
		alunos[i]=(aluno*)malloc(sizeof(aluno));

		if(alunos[i]!=0)leitura(alunos[i]);


	}


	do{
		printf("Digite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime(*alunos[num-1]);

	} while(num);


	for(i=0;i<MAX;i++){
		if(alunos[i]!=0) free(alunos[i]);
	}




	return 0;
}
