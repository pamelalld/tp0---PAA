#include "figuras.h"
#include "cartas.h"

#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main(){

    int opcao,repetir,quantFigura,id;
    tipoFigura quadro[LINHAS][COLUNAS];
    srand(time(NULL));

    int qntJogadores;
    Mesa mesa[LINHAS][COLUNAS];
    Carta** deck=NULL;
    int* divisaoCartas=NULL;

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
            do{
                
                if (quantFigura<=0) quantFigura=sorteiaQuantFiguras();
                resetarQuadro(quadro,&id);
                insereAsterisco(quantFigura,quadro,&id);
                imprimeQuadro(quantFigura,quadro);
                printf("Gostaria de fazer um novo quadro com esses mesmos valores?\n1-SIM\n2-NAO\n");
                scanf("%d",&repetir);
            } while (repetir==1);
            break;
        case 2:
            do{
                if (quantFigura<=0) quantFigura=sorteiaQuantFiguras();
                resetarQuadro(quadro,&id);
                insereCruz(quantFigura,quadro,&id);
                imprimeQuadro(quantFigura,quadro);
                printf("Gostaria de fazer um novo quadro com esses mesmos valores?\n1-SIM\n2-NAO\n");
                scanf("%d",&repetir);
            } while (repetir==1);
            printf("Obrigado por usar o Programa Gerador de Obra de Arte! :)\n");
            break;
        case 3:
            do{
                if (quantFigura<=0) quantFigura=sorteiaQuantFiguras();
                resetarQuadro(quadro,&id);
                insereX(quantFigura,quadro,&id);
                imprimeQuadro(quantFigura,quadro);
                printf("Gostaria de fazer um novo quadro com esses mesmos valores?\n1-SIM\n2-NAO\n");
                scanf("%d",&repetir);
            } while (repetir==1);
            printf("Obrigado por usar o Programa Gerador de Obra de Arte! :)\n");
            break;
        case 4:
            do{
                if (quantFigura<=0) quantFigura=sorteiaQuantFiguras();
                resetarQuadro(quadro,&id);
                sorteiaFigura(quantFigura,quadro,&id);
                imprimeQuadro(quantFigura,quadro);
                printf("Gostaria de fazer um novo quadro com esses mesmos valores?\n1-SIM\n2-NAO\n");
                scanf("%d",&repetir);
            } while (repetir==1);
            printf("Obrigado por usar o Programa Gerador de Obra de Arte! :)\n");
            break;
        default:
            do{
                if (quantFigura<=0) quantFigura=sorteiaQuantCartas();

                deck = sorteiaCartas(quantFigura);
                divisaoCartas = divideCartas(quantFigura, &qntJogadores);

                insereCartas(deck, quantFigura, mesa, divisaoCartas, &qntJogadores);

                imprimeMesa(mesa);

                resetarMesa(mesa,&deck,&divisaoCartas,quantFigura);

                printf("Gostaria de fazer um novo quadro com esses mesmos valores?\n1-SIM\n2-NAO\n");
                scanf("%d",&repetir);
            } while (repetir==1);
            printf("Obrigado por usar o Programa Gerador de Obra de Arte! :)\n");
            break;
    }

    return 0;
}