#ifndef TIPO_CARTA
#define TIPO_CARTA

#include "../include/cartas.h"

#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


Carta* inicializaPaus(char simbolo) {

    Carta* item = malloc(sizeof(Carta));
    item->tipoCarta = 'P';   

    char desenho[6][8] = {
        " sssss ",   //'s' indica borda superior/inferior, representada por '_'
        "l  _  l",   //'l' indica borda lateral, representada por '|'
        "l ( ) l",
        "l(_'_)l",
        "l  |  l",
        "lsssssl"
    };

    desenho[1][1] = simbolo;

    memcpy(item->cartaDesenho, desenho, sizeof(desenho));

    return item;
}

Carta* inicializaCopas(char simbolo) {

    Carta* item = malloc(sizeof(Carta));
    item->tipoCarta = 'C';

    char desenho[6][8] = {
        " sssss ",
        "l _ _ l",
        "l( v )l",
        "l \\ / l",
        "l  '  l",
        "lsssssl"
    };

    desenho[1][1] = simbolo;
    memcpy(item->cartaDesenho, desenho, sizeof(desenho));
    return item;
}

Carta* inicializaOuro(char simbolo) {

    Carta* item = malloc(sizeof(Carta));
    item->tipoCarta = 'O';

    char desenho[6][8] = {
        " sssss ",
        "l  ^  l",
        "l / \\ l",
        "l \\ / l",
        "l  .  l",
        "lsssssl"
    };

    desenho[1][1] = simbolo;
    memcpy(item->cartaDesenho, desenho, sizeof(desenho));
    return item;
}

Carta* inicializaEspada(char simbolo) {

    Carta* item = malloc(sizeof(Carta));
    item->tipoCarta = 'E';

    char desenho[6][8] = {
        " sssss ",
        "l  .  l",
        "l /.\\ l",
        "l(_._)l",
        "l  |  l",
        "lsssssl"
    };

    desenho[1][1] = simbolo;
    memcpy(item->cartaDesenho, desenho, sizeof(desenho));
    return item;
}

int sorteiaQuantCartas(){
    return (rand() % 31+1);
}

void mesaVazia(Mesa mesa[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i==0 || i==LINHAS-1){
                mesa[i][j].caractere='-';
                mesa[i][j].carta=NULL;
            }
            else if (j==0 || j==COLUNAS-1){
                mesa[i][j].caractere='|';
                mesa[i][j].carta=NULL;
            }
            else{
                mesa[i][j].caractere=' ';
                mesa[i][j].carta=NULL;
            }
            
        }
    }
}


Carta** sorteiaCartas(int quantidade){

    Carta** deck = malloc(sizeof(Carta*) * quantidade);

    int cartas[4][12]; // armazena quais cartas ja foram sorteadas para não haver repeticão
    int naipe,valor;

    for (int i=0;i<quantidade;i++){
        do{
            naipe = rand()%4;
            valor = rand()%12;

        }while(cartas[naipe][valor] == 1);

        cartas[naipe][valor] = 1;

        char simbolo;

        switch (valor) {
            case 0:
                simbolo = 'A';
                break;
            case 1:
                simbolo = '2';
                break;
            case 2:
                simbolo = '3';
                break;
            case 3:
                simbolo = '4';
                break;
            case 4:
                simbolo = '5';
                break;
            case 5:
                simbolo = '6';
                break;
            case 6:
                simbolo = '7';
                break;
            case 7:
                simbolo = '8';
                break;
            case 8:
                simbolo = '9';
                break;
            case 9:
                simbolo = 'Q';
                break;
            case 10:
                simbolo = 'J';
                break;
            case 11:
                simbolo = 'K';
                break;     
        }
        switch (naipe) {
            case 0:
                deck[i] = inicializaCopas(simbolo);
                break;
            case 1:
                deck[i] = inicializaOuro(simbolo);
                break;
            case 2:
                deck[i] = inicializaPaus(simbolo);
                break;
            case 3:
                deck[i] = inicializaEspada(simbolo);
                break;
        }
    }
    return deck; //retorna uma lista contendo todas as cartas sorteadas
}

int* divideCartas(int quantidade, int* qntJogadores){

    int maxJogadores=3;
    int minCartas=3;
    int maxCartas=10;

    if (quantidade<=5) (*qntJogadores)=1;
    else{
        for (int i=maxJogadores;i>=1;i--){  //define a quantidade de jogadores com base na quant de cartas, visando sempre o maioe nº possível
            int divisaoCartas= quantidade/i;
            if (divisaoCartas>=minCartas && divisaoCartas<=maxCartas){
                (*qntJogadores)=i;
                break;
            }
        }
    }

    int *qntCartas = malloc(sizeof(int) * (*qntJogadores)); //um array em que cada posicao representa a quantidade de cartas q cada jogador possui
                                                            //obs: pode haver no max 3 jogadores

    int divisaoCartas= quantidade/(*qntJogadores);
    int sobraCartas=quantidade%(*qntJogadores);

    for(int j=0;j<(*qntJogadores);j++){ //distribui as cartas que sobraram

        qntCartas[j] = divisaoCartas;

        if (sobraCartas>0){
            qntCartas[j]++;
            sobraCartas--;
        }
    }

    return qntCartas;

}

void desenhaCarta(Mesa mesa[LINHAS][COLUNAS], Carta* carta, int linha, int coluna) {
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) { //insere as cartas na matriz mesa
                                    
            char c = carta->cartaDesenho[i][j];

            mesa[linha + i][coluna + j].caractere = c;   //[linha][coluna] é o ponto de partida para inserir a carta, a partir dele os iteradores i e j controlam a inserção do restante da figura 
            mesa[linha + i][coluna + j].carta = carta;
            
        }
    }
}

int desviaColisao(int colunas, int usadas[], int qtdUsadas) {
    int pos;
    bool EhValido;
    int tentativas = 0;
    int maxTentativas = 500;

    do {
        EhValido = true;
        pos = 1 + rand() % ((colunas - 1) - 7);

        for (int i = 0; i < qtdUsadas; i++) {
            if (abs(pos - usadas[i]) < 7) {
                EhValido = false;
                break;
            }
        }

        tentativas++;
        if (tentativas > maxTentativas) {
            return -1; //estourou o limite de tentativas, melhor começar do zero
        }

    } while (!EhValido);

    return pos;
}


void insereCartas(Carta** deck, int quantidade, Mesa mesa[LINHAS][COLUNAS], int* divisaoCartas,int* qntJogadores){

    srand(time(NULL));
    bool fim=false;

    while(!fim){
        mesaVazia(mesa);
        fim=true;

        if ((*qntJogadores)==1){

            int colunasUsadas[quantidade];
            int qtdUsadas = 0;

            for (int i = 0; i < quantidade; i++) {
                
                Carta* cartaAtual = deck[i];

                int coluna = desviaColisao(COLUNAS-2, colunasUsadas, qtdUsadas);

                colunasUsadas[qtdUsadas++] = coluna;
                
                desenhaCarta(mesa, cartaAtual, 6, coluna);
            }
        }
        else if ((*qntJogadores)==2){

            int index=0;
            int eixoy[2]={3,LINHAS-9};

            for (int p=0;p<2;p++){

                int usadas[divisaoCartas[p]];
                int qtdUsadas = 0;

                for (int i = 0; i < divisaoCartas[p]; i++) {
                    
                    Carta* cartaAtual = deck[index];
                    index++;
                    int coluna = desviaColisao(COLUNAS-2, usadas, qtdUsadas);
                    usadas[qtdUsadas++] = coluna;
                    
                    desenhaCarta(mesa, cartaAtual, eixoy[p], coluna);
                }
            }

        }
        else{

            int index=0;
            int eixoy[3]={1,7,13};

            for (int p=0;p<3;p++){

                int usadas[divisaoCartas[p]];
                int qtdUsadas = 0;

                for (int i = 0; i < divisaoCartas[p]; i++) {
                    
                    Carta* cartaAtual = deck[index];
                    index++;
                    int coluna = desviaColisao(COLUNAS-2, usadas, qtdUsadas);

                    if (coluna == -1) { //quando atinge 500 tentativas, a mesa é reiniciada e as cartas inseridas novamente do início para buscar uma nova combinação de posições que caiba todas
                        fim = false;
                        break;
                    }
                    usadas[qtdUsadas++] = coluna;
                    
                    desenhaCarta(mesa, cartaAtual, eixoy[p], coluna);
                }
            }
        }
    }

}

void imprimeMesa(Mesa mesa[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {

            char c = mesa[i][j].caractere;

            if(i==0 || i==LINHAS-1 || j==0 || j==COLUNAS-1){ //se for a borda da mesa, imprime branco
                printf("\033[1;37m");
                printf("%c",c);
                printf("\033[0m");
            }
            else{
                if (c == 's'){     //se for a borda superior/inferior da carta, imprime branco
                    c = '_';
                    printf("\033[1;37m");
                    printf("%c",c);
                    printf("\033[0m");

                }
                else if (c == 'l'){    //se for a borda lateral da carta, imprime branco
                    c = '|';
                    printf("\033[1;37m");
                    printf("%c",c);
                    printf("\033[0m");
                }
                else{
                    if (mesa[i][j].carta == NULL) {
                        printf(" ");
                    }
                    else{
                        char tipoCarta=mesa[i][j].carta->tipoCarta;  //decide a cor com base no naipe da carta (vermelho ou cinza escuro)
                        if (tipoCarta=='O' || tipoCarta =='C'){
                            printf("\033[0;31m");
                            printf("%c",c);
                            printf("\033[0m");
                        }
                        else{
                            printf("\033[1;30m");
                            printf("%c",c);
                            printf("\033[0m");
                        }
                    }
                } 
            }
        }
        printf("\n");
    }
}

void resetarMesa(Mesa mesa[LINHAS][COLUNAS], Carta*** deck, int** divisaoCartas,int qntCartas) {

    mesaVazia(mesa);

    if (*deck != NULL) {
        for (int i = 0; i < qntCartas; i++) {
            if ((*deck)[i] != NULL) {
                free((*deck)[i]);
            }
        }
        free(*deck);
        *deck = NULL;
    }

    if (*divisaoCartas != NULL) {
        free(*divisaoCartas);
        *divisaoCartas = NULL;
    }

}


#endif