#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
	char nome[50];
	char numMat[20];
	float notas[4];
	int faltas;
} aluno;

void leitura(aluno *a) {
	int l, i;
	printf("Nome: ");
	gets((*a).nome);
	printf("Numero de Matricula: ");
	gets((*a).numMat);
	for(l = 0; l < 4; l++){
        printf("notas %d:", l);
        scanf("%f", &(*a).notas[l]);
    }
	printf("Faltas: ");
	scanf("%d", &(*a).faltas); getchar();
}

float media(aluno a) {
    float media;

    media = (a.notas[0] + a.notas[1] +a.notas[2] + a.notas[3]) / 4;

  return media;
}

const char* situacao(aluno a){

    char *situacao;
        if (media(a) < 7 || a.faltas > 6){
         situacao = "reprovado";
        } else {
         situacao = "aprovado";
        }
    return situacao;


  }

void imprime(aluno a) {
        printf("Nome: %s\nFaltas: %d\nNumero de Matricula: %s\nMedia: %.2f\nSituacao: %s\n",a.nome, a.faltas, a.numMat, media(a), situacao(a));
}
 main(int i) {
    aluno alunos[MAX];

 	for(i=0;i < MAX; i++) leitura(&alunos[i]);

 	for(i=0; i < MAX; i++) imprime(alunos[i]);

	return 0;
}
