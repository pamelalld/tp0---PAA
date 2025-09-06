#ifndef FIGURAS_H
#define FIGURAS_H

#define LINHAS 20
#define COLUNAS 80

typedef struct tipoFigura{
    char caractere;
    char tipoFig;
    int idFigura;
} tipoFigura;

void criaQuadroVazio (tipoFigura quadro[LINHAS][COLUNAS]);
tipoFigura* inicializaX(int id);
tipoFigura* inicializaPonto(int id);
tipoFigura* inicializaCruz(int id);

void insereAsterisco(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void insereCruz(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void insereX(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);

int sorteiaQuantFiguras();
void sorteiaFigura (int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);

void sorteiaCores(int quant, int vetorCores[]);
void selecionaCor(int id);

void resetarQuadro(tipoFigura quadro[LINHAS][COLUNAS], int *id);
void imprimeQuadro(int quantFiguras, tipoFigura quadro[LINHAS][COLUNAS]);


#endif


