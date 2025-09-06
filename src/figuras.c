#ifndef FIGURAS
#define FIGURAS

#include "../include/figuras.h"

#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void criaQuadroVazio (tipoFigura quadro[LINHAS][COLUNAS]){

    for(int i=0;i<LINHAS;i++){
        for (int j=0;j<COLUNAS;j++){
            if (i==0 || i==LINHAS-1){
                quadro[i][j].caractere='-';
                quadro[i][j].tipoFig='n';
            }
            else if (j==0 || j==COLUNAS-1){
                quadro[i][j].caractere='|';
                quadro[i][j].tipoFig='n';
            }
            else{
                quadro[i][j].caractere=' ';
                quadro[i][j].tipoFig='n';
            }
        }
    }
}


tipoFigura* inicializaX(int id){

    tipoFigura *item;
    item = (tipoFigura*) malloc (sizeof(tipoFigura));
    item->caractere='*';
    item->tipoFig='x';
    item->idFigura=id;

    return item;
}
tipoFigura* inicializaPonto(int id){

    tipoFigura *item;
    item = (tipoFigura*) malloc (sizeof(tipoFigura));
    item->caractere='*';
    item->tipoFig='*';
    item->idFigura=id;

    return item;

}
tipoFigura* inicializaCruz(int id){

    tipoFigura *item;
    item = (tipoFigura*) malloc (sizeof(tipoFigura));
    item->caractere='*';
    item->tipoFig='+';
    item->idFigura=id;

    return item;

}

void sorteiaCores(int quant, int vetorCores[]){

    int aux=0;

    for (int i=0;i<quant;i++){
        aux = rand()%8;
        vetorCores[i]=aux;

    }

}

int sorteiaQuantFiguras(){
    return (rand() % 101+1);
}

void selecionaCor(int id){

    id=id%8;

    switch (id){
        case 0:
            printf("\033[0;33m"); //amarelo
            break;
        case 1:
            printf("\033[0;30m"); //preto
            break;
        case 2:
            printf("\033[0;31m"); //vermelho
            break;
        case 3:
            printf("\033[0;32m"); //verde
            break;
        case 4:
            printf("\033[0;34m"); //amarelo
            break;
        case 5:
            printf("\033[0;35m"); //roxo
            break;
        case 6:
            printf("\033[0;36m"); //ciano
            break;
        case 7:
            printf("\033[1;37m"); //branco
            break;
    }
}

void imprimeQuadro(int quantFiguras, tipoFigura quadro[LINHAS][COLUNAS]){

    int listaCores[quantFiguras];

    sorteiaCores(quantFiguras,listaCores); //determina uma cor para cada id de figura

    for (int i=0;i<LINHAS;i++){
        for (int j=0;j<COLUNAS;j++){
            if (quadro[i][j].tipoFig=='n'){
                printf("%c",quadro[i][j].caractere);
            }
            else{
                selecionaCor(listaCores[quadro[i][j].idFigura]); //recupera a cor associada ao id
                printf("%c",quadro[i][j].caractere);
                printf("\033[0m");
            }
        }
    printf("\n");

    }
}

void insereAsterisco(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id){

    int count=0;
    tipoFigura* pixel;

    while(count<quantidade){
        int i = rand()%LINHAS;
        int j = rand()%COLUNAS;

        if (quadro[i][j].caractere==' '){
            pixel = inicializaPonto(*id);
            quadro[i][j]=*pixel;
            count+=1;
            (*id)++;
        }
    }
}

void insereCruz(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id){

    int count=0;
    tipoFigura* pixel;

    while(count<quantidade){
        int i = rand()%LINHAS;
        int j = rand()%COLUNAS; //sorteia a posição em que a figura será inserida

        if (quadro[i][j].caractere==' ' && quadro[i][j-1].caractere==' ' && quadro[i][j+1].caractere==' ' 
            && quadro[i+1][j].caractere==' ' && quadro[i-1][j].caractere==' ' ){  //verifica se não há colisões

            pixel = inicializaCruz(*id);  
            quadro [i][j]=*pixel;  //atribui cada pixel ao quadro
            quadro[i][j-1]=*pixel;
            quadro[i][j+1]=*pixel;
            quadro[i+1][j]=*pixel;
            quadro[i-1][j]=*pixel;
            count+=1;
            (*id)++;
        }
    }

}

void insereX(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id){

    int count=0;
    tipoFigura* pixel;

    while(count<quantidade){
        int i = rand()%LINHAS;
        int j = rand()%COLUNAS;

        if (quadro[i][j].caractere==' ' && quadro[i-1][j-1].caractere==' ' && quadro[i-1][j+1].caractere==' ' && quadro[i+1][j-1].caractere==' ' && quadro[i+1][j+1].caractere==' ' ){
            pixel=inicializaX(*id);
            quadro [i][j]=*pixel;
            quadro[i-1][j-1]=*pixel;
            quadro[i-1][j+1]=*pixel;
            quadro[i+1][j-1]=*pixel;
            quadro[i+1][j+1]=*pixel;
            count+=1;
            (*id)++;
        }
    }

}

void sorteiaFigura (int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id){

    int figura;

    while (quantidade > 0){

        figura = rand()%3;

        switch (figura){
            case 0:
                insereAsterisco(1,quadro,id);
                break;
            case 1:
                insereCruz(1,quadro,id);
                break;
            case 2:
                insereX(1,quadro,id);
                break;
        }
        quantidade--;
    }
}

void resetarQuadro(tipoFigura quadro[LINHAS][COLUNAS], int *id) {
    *id = 0;
    criaQuadroVazio(quadro);
}

#endif