#include <stdio.h>

/*Voc� precisa armazenar uma lista de c�digos num�ricos, 
a capacidade desta lista � de no m�ximo 20 posi��es.
A Lista n�o pode ter elementos vazios entre os elementos ocupados.*/
typedef struct {
    int vetor[20];
    int posicaoAtual; //posi��o onde o item ser� inserido
} lista;


//a - Consultar a posi��o (0 a 19); Imprimir o c�digo num�rico na tela. 
void consultarElemento(lista *listinha) {
	int posicaoDesejada = 0;
	printf("Indique a posicao desejada:(0 a 19)\n");
    scanf("%d", &posicaoDesejada);
    if(posicaoDesejada >= (*listinha).posicaoAtual) {
    	printf("Nenhum elemento inserido na posicao %d\n\n", posicaoDesejada);
	} else {
		printf("o elemento da posicao %d e %d \n\n", posicaoDesejada, (*listinha).vetor[posicaoDesejada]);	
	}
}

/*
b - Inser��o de um novo elemento na posi��o indicada pelo usu�rio; 
Se o usu�rio indicar uma posi��o ocupada, os elemento deve "andar" para o final; 
Se o usu�rio indicar uma posi��o que ainda n�o foi alcan�ada, o item ser� inserido na �ltima posi��o. posicao < ocupado
*/
void adicionarElemento(lista *listinha) {
    int posicaoDesejada = 0;
    int valor = 0;
    printf("Indique a posicao desejada:(0 a 19) \n");
    scanf("%d", &posicaoDesejada);
    printf("Indique o valor desejado: \n");
    scanf("%d", &valor);
    
    //Se o usu�rio indicar uma posi��o que ainda n�o foi alcan�ada, o item ser� inserido na �ltima posi��o
    if(posicaoDesejada < (*listinha).posicaoAtual) { // valida��o para saber se a inser��o ser� feita no meio ou final da lista
        int listaAuxiliar[20];
        int contador;
        for(contador = 0; contador < 20; contador++) {
            if(contador < posicaoDesejada) { 
                listaAuxiliar[contador] = (*listinha).vetor[contador];
            } else if(contador > posicaoDesejada) {
            	if(contador+1 < 20) {
					listaAuxiliar[contador+1] = (*listinha).vetor[contador];	
				}
            } else {
                listaAuxiliar[contador] = valor;
                if(contador+1 < 20) {
                	listaAuxiliar[contador+1] = (*listinha).vetor[contador];
                }
            }
        }
        for(contador = 0; contador < 20; contador++) { // transferindo valores da lista auxiliar para a lista original
        	(*listinha).vetor[contador] = listaAuxiliar[contador];
		}
    } else {
        (*listinha).vetor[(*listinha).posicaoAtual] = valor;
    }
    (*listinha).posicaoAtual++;
}

//c - Retirar um elemento indicado pelo usu�rio; Se houver elementos posteriores, estes devem tomar a posi��o que ficou livre;
void removerElemento(lista *listinha) {
	int listaAuxiliar[20];
    int contador;
	int posicaoDesejada = 0;
    printf("Indique a posicao que deseja remover:(0 a 19) \n");
    scanf("%d", &posicaoDesejada);
    if((*listinha).posicaoAtual == 0 || posicaoDesejada >= (*listinha).posicaoAtual) { 
    	printf("Nenhum elemento na posi��o indicada \n");
	} else {
		if(posicaoDesejada == (*listinha).posicaoAtual - 1) {
			for(contador = 0; contador < 20; contador++) {
				if(contador != posicaoDesejada) {
					listaAuxiliar[contador] = (*listinha).vetor[contador];
				}
			}
		} else {
			for(contador = 0; contador < 20; contador++) {
				if(contador != posicaoDesejada) {
					listaAuxiliar[contador] = (*listinha).vetor[contador];
				}
				
				if(contador < posicaoDesejada) {
                	listaAuxiliar[contador] = (*listinha).vetor[contador];
	            } else {
	            	if(contador+1 < 20) {
						listaAuxiliar[contador] = (*listinha).vetor[contador+1];	
					}
	            }
			}
			for(contador = 0; contador < 20; contador++) {
        		(*listinha).vetor[contador] = listaAuxiliar[contador];
	     	}
		}
		(*listinha).posicaoAtual--;
	}
}

//d - Consultar a quantidade de elementos;
void consultarQuantidadeElementos(lista *listinha) {
	printf("Existem %d elementos na lista \n\n", (*listinha).posicaoAtual);
}

int main()
{
	lista listinha;
	int comando = 0;
	do {
    	printf("Entre com o comando desejado:\n");
    	printf("1 - Consultar posicao: \n");
    	printf("2 - Inserir um novo elemento:\n");
    	printf("3 - Retirar um elemento:\n");
    	printf("4 - Consultar quantidade de elementos :\n");
    	printf("0 - Para sair\n");
    	
    	 scanf("%d", &comando);
    	
    	switch(comando) {
    		case 1:
    			consultarElemento(&listinha);
    			break;
    		case 2:
    			adicionarElemento(&listinha);
    			break;
    		case 3:
    			removerElemento(&listinha);
    			break;
    		case 4:
    			consultarQuantidadeElementos(&listinha);
    			break;
    		case 0:
    			break;
    		default:
    			printf ("Valor invalido!\n");
    			break;
		}
	} while(comando!=0);

    return 0;
}
/*
Dica:
i. Usar um vetor de inteiros de 20 posi��es; 
ii. armazenar em um n�mero inteiro a quantidade de elementos ocupados; se ocupados � igual a zero, 
significa que o vetor est� vazio, se ocupados � igual a 20 significa que a lista est� cheia;
*/
