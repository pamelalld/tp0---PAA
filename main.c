#include "figuras.h"
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

int main(){

    int opcao,quantFigura,id=0;
    TipoPincel quadro[20][80];
    srand(time(NULL));

    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n"
            "=================================\n"
            "Escolha o tipo de figura basica a ser usada para criar a obra:\n"
            "1 - asterisco simples.\n"
            "2 - simbolo de soma com asteriscos.\n"
            "3 - letra X com asteriscos.\n"
            "4 - figuras aleatorias\n"
            "5 ou qualquer outro numero - opcao de obra de arte criada pelo aluno\n");

    printf("=================================\n");       
    printf("Digite o tipo de figura basica desejada:");
    scanf("%d",&opcao);
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
    scanf("%d",&quantFigura);

    switch (opcao){

        case 1:
            criaQuadroVazio(20,80,quadro);
            insereAsterisco(quantFigura,20,80,quadro,&id);
            imprimeQuadro(quantFigura,20,80,quadro);
            break;
        case 2:
            criaQuadroVazio(20,80,quadro);
            insereCruz(quantFigura,20,80,quadro,&id);
            imprimeQuadro(quantFigura,20,80,quadro);
            break;
        case 3:
            criaQuadroVazio(20,80,quadro);
            insereX(quantFigura,20,80,quadro,&id);
            imprimeQuadro(quantFigura,20,80,quadro);
            break;
        case 4:
            criaQuadroVazio(20,80,quadro);
            sorteiaFigura(quantFigura,20,80,quadro,&id);
            imprimeQuadro(quantFigura,20,80,quadro);
            break;
        case 5:
            //
            break;
        default:
            printf("Opcao inválida");
            break;
    }

    return 0;
}