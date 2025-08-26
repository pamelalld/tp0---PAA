#ifndef FIGURAS
#define FIGURAS

#include <stdio.h>
#include <time.h>
#include "tipoPincel.h"
#include <stdlib.h>

void criaQuadroVazio (int linhas,int colunas, TipoPincel quadro[linhas][colunas]){

    for(int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            if (i==0 || i==linhas-1){
                quadro[i][j].caractere='-';
                quadro[i][j].tipoFig='n';
            }
            else if (j==0 || j==colunas-1){
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

void sorteiaCores(int quant, int vetorID[], int vetorCores[]){

    int aux=0;

    for (int i=0;i<quant;i++){
        aux = rand()%8;
        vetorID[i]=i;
        vetorCores[i]=aux;

    }

}

void selecionaCor(int id){

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

void imprimeQuadro(int quantFiguras, int linhas, int colunas, TipoPincel quadro[linhas][colunas]){

    int listaIds[quantFiguras];
    int listaCores[quantFiguras];

    sorteiaCores(quantFiguras,listaIds,listaCores);

    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            if (quadro[i][j].tipoFig=='n'){
                printf("%c",quadro[i][j].caractere);
            }
            else{
                selecionaCor(listaCores[quadro[i][j].idFigura]);
                printf("%c",quadro[i][j].caractere);
                printf("\033[0m");
            }
        }
    printf("\n");

    }
}

void insereAsterisco(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id){
  
    int count=0;
    TipoPincel* pixel;

    while(count<quantidade){
        int i = rand()%linhas;
        int j = rand()%colunas;

        if (quadro[i][j].caractere==' '){
            pixel = inicializaPonto(*id);
            quadro[i][j]=*pixel;
            count+=1;
            (*id)++;
        }
    }
}

void insereCruz(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id){
  
    int count=0;
    TipoPincel* pixel;

    while(count<quantidade){
        int i = rand()%linhas;
        int j = rand()%colunas;

        if (quadro[i][j].caractere==' ' && quadro[i][j-1].caractere==' ' && quadro[i][j+1].caractere==' ' && quadro[i+1][j].caractere==' ' && quadro[i-1][j].caractere==' ' ){
            pixel = inicializaCruz(*id);
            quadro [i][j]=*pixel;
            quadro[i][j-1]=*pixel;
            quadro[i][j+1]=*pixel;
            quadro[i+1][j]=*pixel;
            quadro[i-1][j]=*pixel;
            count+=1;
            (*id)++;
        }
    }

}

void insereX(int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id){
  
    int count=0;
    TipoPincel* pixel;

    while(count<quantidade){
        int i = rand()%linhas;
        int j = rand()%colunas;

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

void sorteiaFigura (int quantidade,int linhas,int colunas,TipoPincel quadro[linhas][colunas],int* id){

    int figura;

    while (quantidade > 0){

        figura = rand()%3;

        switch (figura){
            case 0:
                insereAsterisco(1,linhas,colunas,quadro,id);
                break;
            case 1:
                insereCruz(1,linhas,colunas,quadro,id);
                break;
            case 2:
                insereX(1,linhas,colunas,quadro,id);
                break;
        }
        quantidade--;
    }
}

// int main(){

//     TipoPincel quadro[20][80];
//     int quant=0;
//     srand(time(NULL));

//     scanf("%d",&quant);

//     criaQuadroVazio(20,80,quadro);
//     insereX(quant,20,80,quadro);
//     imprimeQuadro(quant,20,80,quadro);
//     return 0;

// }

#endif