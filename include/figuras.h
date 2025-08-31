#ifndef FIGURAS_H
#define FIGURAS_H

#define LINHAS 20
#define COLUNAS 80

typedef struct tipoFigura{
    char caractere;
    char tipoFig;
    int idFigura;
} tipoFigura;


tipoFigura* inicializaX(int id);
tipoFigura* inicializaPonto(int id);
tipoFigura* inicializaCruz(int id);

void criaQuadroVazio (tipoFigura quadro[LINHAS][COLUNAS]);
void sorteiaCores(int quant, int vetorID[], int vetorCores[]);
void selecionaCor(int id);
void imprimeQuadro(int quantFiguras, tipoFigura quadro[LINHAS][COLUNAS]);
void insereAsterisco(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void insereCruz(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void insereX(int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void sorteiaFigura (int quantidade,tipoFigura quadro[LINHAS][COLUNAS],int* id);
void resetarQuadro(tipoFigura quadro[LINHAS][COLUNAS], int *id);
int sorteiaQuantFiguras();


#endif
