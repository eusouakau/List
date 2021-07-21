#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1

typedef struct {
	char nome[50];
	char numMat[20];
	float notas[4];
	int faltas;
} aluno;

aluno a[MAX];

void leitura(int i) {
	int l;
	printf("Nome: ");
	gets(a[i].nome);
	printf("Numero de Matricula: ");
	gets(a[i].numMat);
	for(l = 0; l < 4; l++){
        printf("notas %d:", l);
        scanf("%f", &a[i].notas[l]);
    }
	printf("Faltas: ");
	scanf("%d", &a[i].faltas); getchar();
}

float media(int i) {
    float media;
    media = (a[i].notas[0] + a[i].notas[1] +a[i].notas[2] + a[i].notas[3]) / 4;

  return media;
}

const char* situacao(i){
  char *situacao;
    if (media(i) < 7 || a[i].faltas > 6){
     situacao = "reprovado";
    }
    else {
     situacao = "aprovado";
    }
    return situacao;


  }

void imprime(int i) {
        printf("Nome: %s\nFaltas: %d\nNumero de Matricula: %s\nMedia: %.2f\nSituacao: %s\n",a[i].nome, a[i].faltas, a[i].numMat, media(i), situacao(i));
}
 main(int i) {

 	for(i=0;i < MAX; i++) leitura(i);

 	for(i=0; i < MAX; i++) imprime(i);

	return 0;
}

