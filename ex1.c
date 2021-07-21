#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

char nome[40];

char telefone[15];

} contato;

int main(int argc, char *argv[]){

contato *teste;

teste = (contato*)malloc(sizeof(contato));

gets((*teste).nome);

strcpy((*teste).telefone, "1234567");

printf("endereco antes: %d\n", &teste);

printf("Nome = %s\nTelefone = %s\n",(*teste).nome,(*teste).telefone);

printf("endereco depois: %d\n", &teste);

free(teste);
}
