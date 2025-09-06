#ifndef TIPO_CARTA_H
#define TIPO_CARTA_H

#define LINHAS 20
#define COLUNAS 80

typedef struct Carta{
    char tipoCarta;
    char cartaDesenho[6][8];
} Carta;

typedef struct Mesa{
    char caractere;
    Carta* carta;
} Mesa;

void mesaVazia(Mesa mesa[LINHAS][COLUNAS]);
Carta* inicializaPaus(char simbolo);
Carta* inicializaCopas(char simbolo);
Carta* inicializaOuro(char simbolo);
Carta* inicializaEspada(char simbolo);

Carta** sorteiaCartas(int quantidade);
int sorteiaQuantCartas();

int* divideCartas(int quantidade, int* qntJogadores);
void insereCartas(Carta** deck, int quantidade, Mesa mesa[LINHAS][COLUNAS], int* divisaoCartas,int* qntJogadores);
int desviaColisao(int colunas, int usadas[], int qtdUsadas);
void desenhaCarta(Mesa mesa[LINHAS][COLUNAS], Carta* carta, int linha, int coluna);


void imprimeMesa(Mesa mesa[LINHAS][COLUNAS]);
void resetarMesa(Mesa mesa[LINHAS][COLUNAS], Carta*** deck, int** divisaoCartas,int qntCartas);

#endif
